#include <iostream>

#include <tuple>

#include <algorithm>

using namespace std;
void InputValues(int & a, int & b, int & c) {
  cout << "Enter a value for 'a': ";
  while (!(cin >> a)) {
    cout << "Please input an integer value for 'a': ";
    cin.clear();
    cin.ignore(10000, '\n');
  }
  cin.ignore(10000, '\n');

  cout << "\nEnter a value for 'b': ";
  while (!(cin >> b)) {
    cout << "Please input an integer value for 'b': ";
    cin.clear();
    cin.ignore(10000, '\n');
  }
  cin.ignore(10000, '\n');

  cout << "\nEnter a value for 'c': ";
  while (!(cin >> c)) {
    cout << "Please input an integer value for 'c': ";
    cin.clear();
    cin.ignore(10000, '\n');
  }
  cin.ignore(10000, '\n');

}
void ConfirmValues(int & A, int & B, int & C, int & Confirm) {
  int a, b, c;
  Confirm = 0;
  while (Confirm != 1) {
    InputValues(a, b, c);
    cout << "Please confirm the values a: " << a << ", b: " << b << ", c: " << c << "\n\n1. Correct\n2. Change\nInput: ";

    cin >> Confirm;

    if (Confirm == 1) {
      break;
    } else {}
  }

  A = a;
  B = b;
  C = c;
  cout << "\n\n";
}
void ExtendedEuclideanAlgorithm(int & EA, int & EB, int & EC, int & D, bool & Sol) {
  int A, B, C, Confirm, Q;
  ConfirmValues(A, B, C, Confirm);
  EA = abs(A);
  EB = abs(B);
  EC = C;

  if (EA == 0) {
    D = EB;
  } else if (EB == 0) {
    D = EA;
  } else if (EA == EB) {
    D = EA;
  } else if (EA > EB) {
    D = abs(__gcd(EA - EB, EB));
  } else if (EA < EB) {
    D = abs(__gcd(EA, EB - EA));
  }
  if (D == 0){
        Sol = (EC == 0);

  } else if (EC % D == 0) {
    Sol = true;
  } else {
    Sol = false;
  }
}

int main() {
  int EA, EB, EC, D;
  bool Sol;
  cout << "Linear Diophantine Calculator\n";
  cout << "This calculator uses the format 'a''x' + 'b''y' = c\nNote that all decimal values will be rounded down to the nearest integer\n\n";
  ExtendedEuclideanAlgorithm(EA, EB, EC, D, Sol);
  cout << "a: " << EA << ", b: " << EB << ", c: " << EC << " Greatest Common Denominator of A and B: " << D;
  if (Sol == true) {
    cout << "\nEquation is Solvable";
  } else if (Sol == false) {
    cout << "\nEquation is not Solvable";
  }
}
