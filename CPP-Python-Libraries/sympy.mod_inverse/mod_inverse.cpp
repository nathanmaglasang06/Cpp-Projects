//
// Created by Nathan Maglasang on 3/10/2025.
//

#include "stdc++.h"
using namespace std;

// Extended Euclidean Algorithm
// Finds gcd(a,b) and coefficients x,y such that: a*x + b*y = gcd(a,b)
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = (a >= 0 ? 1 : -1);
        y = 0;
        return llabs(a);
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Modular inverse function: returns optional<long long>
// If inverse exists, returns x with 0 <= x < m
optional<long long> mod_inverse(long long a, long long m) {
    if (m <= 0) throw invalid_argument("Modulus must be positive");
    long long x, y;
    long long g = extended_gcd(a, m, x, y);
    if (g != 1) {
        // Inverse does not exist if gcd ≠ 1
        return nullopt;
    }
    long long inv = (x % m + m) % m; // normalize into [0, m-1]
    return inv;
}

// Demo
int main() {
    // Example 1: inverse exists
    auto inv1 = mod_inverse(3, 11); // 3*4 ≡ 1 mod 11
    if (inv1) cout << "Inverse of 3 mod 11 = " << *inv1 << "\n";
    else cout << "No inverse\n";

    // Example 2: no inverse (gcd(6,9) ≠ 1)
    auto inv2 = mod_inverse(6, 9);
    if (inv2) cout << "Inverse of 6 mod 9 = " << *inv2 << "\n";
    else cout << "No inverse\n";

    return 0;
}