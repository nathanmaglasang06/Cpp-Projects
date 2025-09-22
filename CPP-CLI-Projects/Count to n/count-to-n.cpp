#include <atomic>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using u64 = std::uint64_t;
using steady_clock_t = std::chrono::steady_clock;

static void draw_progress(u64 done, u64 cap, int barWidth) {
    const int pct = static_cast<int>((100uLL * done) / cap);
    const int pos = static_cast<int>((static_cast<u64>(barWidth) * done) / cap);

    static thread_local std::string bar;
    bar.assign(barWidth, ' ');
    for (int i = 0; i < barWidth; ++i) bar[i] = (i < pos) ? '=' : ' ';
    if (pos >= 0 && pos < barWidth) bar[pos] = '>';

    std::cout << '[' << bar << "] " << pct << " %\r";
    std::cout.flush();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const u64 cap = 100'000'000'000ULL;
    const int barWidth = 70;

    const auto started = steady_clock_t::now();

    const unsigned hw = std::max(1u, std::thread::hardware_concurrency());
    const unsigned T = hw;
    const u64 chunk = cap / T;
    const u64 remainder = cap % T;

    std::atomic<u64> done{0};

    auto worker = [&](u64 begin, u64 end) {
        constexpr u64 REPORT_BATCH = 1'000'000ULL;
        u64 local = 0;

        for (u64 n = begin; n < end; ++n) {

            if (++local >= REPORT_BATCH) {
                done.fetch_add(local, std::memory_order_relaxed);
                local = 0;
            }
        }
        if (local) done.fetch_add(local, std::memory_order_relaxed);
    };

    std::vector<std::thread> pool;
    pool.reserve(T);
    u64 start_i = 0;
    for (unsigned i = 0; i < T; ++i) {
        u64 cnt = chunk + (i < remainder ? 1 : 0);
        u64 end_i = start_i + cnt;
        pool.emplace_back(worker, start_i, end_i);
        start_i = end_i;
    }

    bool running = true;
    std::thread progressThr([&]{
        using namespace std::chrono_literals;
        u64 last_drawn = ~0ULL;
        while (running) {
            u64 d = done.load(std::memory_order_relaxed);
            if (d != last_drawn) {
                draw_progress(d, cap, barWidth);
                last_drawn = d;
            }
            std::this_thread::sleep_for(100ms);
        }
        draw_progress(cap, cap, barWidth);
        std::cout << '\n';
    });

    for (auto &th : pool) th.join();
    running = false;
    progressThr.join();

    const auto end = steady_clock_t::now();
    std::cout << "Threads: " << T << "\n";
    std::cout << "Process took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - started).count()
              << " ms\n";
    return 0;
}
