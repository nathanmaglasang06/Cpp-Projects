//
// Created by Nathan Maglasang on 17/10/2025.
//

#include <iostream>
using namespace std;

int main() {
    long long p = 35629792823;
    long long q = 15996463537;
    long long n = p*q;
    long long e = 29;
    long long phi = (p-1)*(q-1);

    cout << "n: " << n << ", phi: "<< phi <<  endl;


}