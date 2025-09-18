#include <iostream>
#include <cmath>

using namespace std;

void InputValues(int & u) {
  cout << "\n\nEnter a integer value to calculate the prime number: ";
  while (!(cin >> u)) {
    cout << "Please input an integer value for the upper limit: ";
    cin.clear();
    cin.ignore(10000, '\n');
  }
cin.ignore(10000, '\n');

}
void ConfirmValues(int & n) {
  int u;
  int Confirm = 0;
  while (Confirm != 1) {
    InputValues(u);
    cout << "Please confirm the values for the nth prime: " << u << "\n\n1. Correct\n2. Change\nInput: ";

    cin >> Confirm;

    if (Confirm == 1) {
        break;
    } else {}
  }
  n = u;
  cout << "\n\n";
}
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0)
            return false;
    return true;
}

int nthPrime(int n) {
    int count = 0;
    int num = 1;

    while (count < n) {
        num++;
        if (isPrime(num))
            count++;
    }
    return num;
}



int main() {
  int n;
  cout << "Prime Number Calculator\n";
  cout << "Enter an integer value to find the associated prime number, ie 5 = 11 \nNote: Decimal values will be rounded down to the nearest integer";
  ConfirmValues(n);
  cout << "The " << n << " th prime is " << nthPrime(n);
}
