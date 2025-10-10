//
// Created by Nathan Maglasang on 27/9/2025.
//

//add -std=c++17 to compiler settings
// sub 10 seconds until 10^5, takes ~30 seconds with 8 threads

#include <iostream>
#include <numeric>
#include <fstream>
#include <thread>
#include <mutex>

using namespace std;

using i64 = long long;
/*ofstream out("factortime.csv");
out << "Nano Seconds,Value_of_n\n";
for (auto [time, n] : recordtime) {
    out << time << "ns," << n << " n\n";


}
out.close();
*/



mutex csv_mutex;
i64 EuclideanCount(i64 a, i64 b) {
    ofstream  out("v1.csv");
    out << "iteration,a,b\n";

    int count = 0;
    while (b != 0) {
        out << count << "," << a << "," << b << "\n";

        i64 temp = b;
        b = a % b;
        a = temp;
        count++;
    }
    out.close();
    return count;
}
i64 EuclideanCount_v2(i64 a, i64 b) {
    ofstream  out2("v2.csv");
    out2 << "iteration,a,b,r,branch\n";
    i64 count = 0;
    while (b != 0) {
        i64 r = a % b;
        string branch = "";

        if (r == 0) {
            out2 << count << "," << a << "," << b << "," << r << ",break\n";

            break;
        }
        if (r < (b / 2)) {
            branch = "r < b/2";

            i64 temp = b;
            b = r;
            a = temp;
        } else {
            branch = "r >= b/2";

            i64 temp = b;
            b = b - r;
            a = temp;
        }
        out2 << count << "," << a << "," << b << "," << r << "," << branch << "\n";

        count++;
    }
    out2.close();
    return count;
}


void worker(int start, int end, int n, i64 &res1, i64 &res2, i64 &better_v2, ofstream &thact) {
    i64 local1 = 0, local2 = 0, local_better = 0;
    for (int a = start; a < end; a++) {
        for (int b = 1; b <= n; b++) {
            i64 c1 = EuclideanCount(a, b);
            i64 c2 = EuclideanCount_v2(a, b);

            local1 += c1;
            local2 += c2;

            if (c2 == c1) local_better++;

            {
                lock_guard<mutex> lock(csv_mutex);
                thact << this_thread::get_id() << "," << a << "," << b << "," << c1 << "," << c2 << "," << (c1 == c2 ? "equal" : "diff") << "\n";
            }

        }
    }
    res1 = local1;
    res2 = local2;
    better_v2 = local_better;
}

int main() {
    int n;
    cout << "Enter a n: ";
    cin >> n;
    ofstream  thact("threadactivity.csv");
    thact << "thread_id,a,res1,res2,better\n"; // CSV header

    int num_threads = thread::hardware_concurrency(); //gets sthe number fo threads: in my case 8, one for each core because mac has weird allocation of 'efficiency' cores for system operatons
    cout << "Number of threads: " << num_threads << "\n";

    vector<thread> threads;
    vector<i64> partial1(num_threads, 0), partial2(num_threads, 0), partialBetter(num_threads, 0); //used to store the partial results from each threads runtime, as the original vector pair was storing 1 million + objects in sys memory

    int chunk = (n - 1 ) / num_threads; // seperates the range for a ot for mutliple threads to use

    for (int t = 0; t < num_threads; t++) {
        //loop creates and launces thread for each chunk of work
        int start = t * chunk + 1;
        int end = (t == num_threads - 1) ? n : (t + 1) * chunk + 1; //number of values each thread has to run
        threads.emplace_back(worker, start, end, n, ref(partial1[t]), ref(partial2[t]), ref(partialBetter[t]), ref(thact)); // launches th threads to actuially do the work
    }
    for (auto &th : threads) { //waits for all the threads to end
        th.join();
    }

    i64 total1 = accumulate(partial1.begin(), partial1.end(), 0LL); //where the twho groups of partial results are totaled
    i64 total2 = accumulate(partial2.begin(), partial2.end(), 0LL);
    i64 totalBetter = accumulate(partialBetter.begin(), partialBetter.end(), 0LL);


    cout << "Total count of steps for Euclidean: " << total1 << "\n";
    cout << "Total count of steps for Euclidean v2: " << total2 << "\n";
    cout << "Number of (a,b) pairs where v2 is equal to v1: " << totalBetter << "\n";

    return 0;
}




