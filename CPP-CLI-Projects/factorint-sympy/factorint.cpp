#include "./stdc++.h"
#include <numeric>
#include <cstdlib>
#include <fstream>
using namespace std;

// Multiplication modulo n (avoids overflow)
long long mulmod(long long a, long long b, long long mod) {
    __int128 res = (__int128)a * b % mod;
    return (long long)res;
}

// Fast modular exponentiation
long long modpow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = mulmod(result, base, mod);
        base = mulmod(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// Miller–Rabin primality test
bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n % p == 0) return n == p;
    }

    long long d = n-1, s = 0;
    while ((d & 1) == 0) { d >>= 1; s++; }

    auto check = [&](long long a) {
        if (a % n == 0) return true;
        long long x = modpow(a, d, n);
        if (x == 1 || x == n-1) return true;
        for (int i = 1; i < s; i++) {
            x = mulmod(x, x, n);
            if (x == n-1) return true;
        }
        return false;
    };

    for (long long a : {2,325,9375,28178,450775,9780504,1795265022}) {
        if (!check(a)) return false;
    }
    return true;
}

// Pollard's Rho
long long rho(long long n) {
    if (n % 2 == 0) return 2;
    long long x = rand() % (n-2) + 2;
    long long y = x;
    long long c = rand() % (n-1) + 1;
    long long d = 1;
    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        d = gcd(abs(x-y), n);
        if (d == n) return rho(n);
    }
    return d;
}

// Recursive factorization
void factorize(long long n, map<long long,int>& factors) {
    if (n == 1) return;
    if (isPrime(n)) {
        factors[n]++;
        return;
    }
    long long d = rho(n);
    factorize(d, factors);
    factorize(n/d, factors);
}

int main() {
    long long n;
    vector<int> base;
    vector<int> exponentsum;
    vector<int> exponentsumout;
    vector<pair<int,int>> recordtime;
    //cout << "Enter value: ";

    //cin >> n;

    //start timer
    auto started = chrono::high_resolution_clock::now();



    //For loop values to add exponent sum values betweeen 10^6 and 2x10^6
    for ( n = 1000000; n < 2000000; n++) {
        auto facstart = chrono::high_resolution_clock::now();

        map<long long,int> factors;
        factorize(n, factors);

        for (auto [p, e] : factors) {
            exponentsum.push_back(e);
        }
        exponentsumout.push_back(accumulate(exponentsum.begin(), exponentsum.end(), 0LL));
        exponentsum.clear();
        auto facend = chrono::high_resolution_clock::now();
        int time = chrono::duration_cast<chrono::nanoseconds>(facend - facstart).count();
        recordtime.push_back({time, n});

    }
    float totalavg = accumulate(exponentsumout.begin(), exponentsumout.end(), 0LL);
    float divisor = 1000000;
    float result = totalavg / divisor;
    cout << "Average value of factorOut between 10^6 and 2 x 10^6:  " << totalavg << "/" << divisor << "=" <<  result << endl;
    auto ended = chrono::high_resolution_clock::now();
    cout << "Process took " << chrono::duration_cast<chrono::milliseconds>(ended - started).count() << " miliseconds" <<endl;
    ofstream out("factortime.csv");
    out << "Nano Seconds,Value_of_n\n";
    for (auto [time, n] : recordtime) {
        out << time << "ns," << n << " n\n";


    }
    out.close();
}

/*cout << "\nExponent Values: ";
    for (int num : exponent1) {
        cout << num << ",";
    }*/