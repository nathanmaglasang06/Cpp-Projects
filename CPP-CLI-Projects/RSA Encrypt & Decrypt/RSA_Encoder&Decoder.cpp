//
// Created by Nathan Maglasang on 18/9/2025.

//Amazing Videos by Eddie Woo
//Part 1: https://youtu.be/4zahvcJ9glg?si=royT9xRM5mkBgZk0
//Part 2: https://youtu.be/oOcTVTpUsPQ?si=j8zTFfKQvDq5bi0S

//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int modPow(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    for (int i = 0; i < exponent; i++) {
        result = (result * base) % modulus;
    }
    return result;
}

string encode(string encryptString, int encrypt[]) {
    cout << encryptString << encrypt[0] << encrypt[1] << endl;
    vector<int> numericTranslation;
    vector<int> numericTransformation;
    string encodedString;

    for (char c : encryptString) {
        if (c >= 'a' && c <= 'z') {
            numericTranslation.push_back(c - 'a' + 1);
        } else {
            numericTranslation.push_back(0);
        }
    }
    cout << "Numeric translation: ";
    for (int num : numericTranslation) {
        cout << num << " ";
        if (num >= 1) {
            numericTransformation.push_back(modPow(num, encrypt[0], encrypt[1]));
        }
    }
    cout << "\nNumeric transformation: ";
    for (int num : numericTransformation) {
        cout << num << " ";
    }
    for (int num : numericTransformation) {
        if (num >= 1 && num <= 26) {
            char c = 'a' + (num - 1);
            encodedString.push_back(c);
        } else {
            encodedString.push_back(' ');
        }
    }
    cout << "\nEncoded String: " << encodedString;
    cout << endl;
    return encodedString;
}

string decode(string decryptString, int decrypt[]) {

    cout << decryptString << decrypt[0] << decrypt[1] << endl;
    vector<int> numericTranslation;
    string decodedString = "WIP";

    for (char c : decryptString) {
        if (c >= 'a' && c <= 'z') {
            numericTranslation.push_back(c - 'a' + 1);
        } else {
            numericTranslation.push_back(0);
        }
    }
    cout << "Numeric translation: ";
    for (int num : numericTranslation) {
        cout << num << " ";
    }

    cout << endl;
return decodedString;
}




int main() {
    int encrypt[2]; //(e,n)
    int decrypt[2]; //(d,n)
    int selection;
    string encryptString, decryptString;



    cout << "RSA (Rivest Shamir Adelman) Encoder and Decoder App"
    "\nWould you like to encrypt or decrypt your message?"
    "\n1. Encrypt\n2. Decrypt\nSelection: ";
    cin >> selection;
    cin.clear();
    cin.ignore(10000, '\n');

    while (selection != 1 && selection != 2) {
        cout << "\n\nInvalid Selection, Try Again: \n1. Encrypt\n2. Decrypt\nSelection: ";
        cin >> selection;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    switch (selection) {
        case 1:
            cout << "\nEncrypt 1"
            "\nFor the public key (e, n) enter the integer value for e: ";

            while (!(cin >> encrypt[0])) {
                cout << "Ensure the value for e is an integer: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cout << "\nNow for the public key (e, n) enter the integer value for n: ";

            while (!(cin >> encrypt[1])) {
                cout << "Ensure the value for e is an integer: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cout  << "\n\nInput the alpha numeric string to encrypt [a-z]: ";
            cin >> encryptString;
            encode(encryptString, encrypt);
            break;

        case 2:
            cout << "\nDecrypt 2"
            "\nFor the private key (d, n) enter the integer value for d: ";

            while (!(cin >> decrypt[0])) {
                cout << "Ensure the value for e is an integer: ";
                cin >> decrypt[0];
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cout << "\nNow for the public key (e, n) enter the integer value for n: ";

            while (!(cin >> decrypt[1])) {
                cout << "Ensure the value for e is an integer: ";
                cin >> decrypt[1];
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cout  << "\n\nInput the Encrypted alpha numeric string [a-z]: ";
            cin >> decryptString;
            decode(decryptString, decrypt);
            break;

    }

    return 0;
}