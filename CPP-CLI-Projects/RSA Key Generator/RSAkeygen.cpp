//
// Created by Nathan Maglasang on 23/10/2025.
//
//

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>


using namespace std;
using lint = long long int;

lint keygen(lint &p, lint &q, lint &n, lint &d, lint &e) {
    lint response = 0;
    lint eco = 0;
    cout << "Do you have your own values for p and q?\n1. Yes\n2. No\nResponse: ";
    cin >> response;
    switch (response) {
        case 1:
            cout << "Input p: ";
            cin >> p;
            cout << "Input q: ";
            cin >> q;
            n = p * q;
            eco = (p-1) * (q-1);
            cout << "Choose a value for e, noting that it must be coprime to " << eco << ": ";
            cin >> e;
            while (true) {
                while (!(cin>>e)) {
                    cout << "Ensure the value for e is an integer: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (gcd(e, eco) == 1) {
                    break;
                } else {
                    cout << "Ensure the value for e is coprime to " << eco << ": ";
                }
            }
            //(e*d) mod (phi(n)) = 1
            //d= e^−1 * modφ(n)
            d = (lint) pow(e, -1) % eco;



            break;

        case 2:
            cout << "No";
            break;

    }


return p, q, n, d, e;
}


int main() {

            cout << "\nRSA Key Generation\n";
            lint p, q, n, d, e;
            p = q = n = d = e = 0;
            keygen(p, q, n, d, e);

            cout << "\np: " << p << ", q: " << q << ", n: " << n << ", d: " << d << ", e: " << e;

    return 0;
}