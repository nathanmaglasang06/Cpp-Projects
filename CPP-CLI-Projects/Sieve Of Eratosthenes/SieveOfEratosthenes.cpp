//
// Created by Nathan Maglasang on 18/9/2025.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
vector<bool> isPrime(n + 1, true);
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }
    vector<int> res;
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            res.push_back(p);
        }
    }

    return res;
}

int main() {

    int n;
    cout << "Sieve of Eratosthenes Calculation\nThis calculator will find all primes from 0 --> n ";
    cout << "\n\nPlease enter the upper limit for the sieve calculation (n): ";
    cin >> n;
    vector<int> res = sieve(n);
    for(auto ele : res) {
        cout << ele << " ";
    }
    return 0;
}