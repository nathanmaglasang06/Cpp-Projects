#include <iostream>

using namespace std;
void InputValues(int & a, int & b) {
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

}
void ConfirmValues(int & A, int & B, int & Confirm) {
  int a, b;
  Confirm = 0;
  while (Confirm != 1) {
    InputValues(a, b);
    cout << "Please confirm the values a: " << a << ", b: " << b << "\n\n1. Correct\n2. Change\nInput: ";

    cin >> Confirm;

    if (Confirm == 1) {
        break;
    } else {}
  }

  A = a;
  B = b;
  cout << "\n\n";
}
void CalculateRemainder(int &CA, int &CB, int &Out) {
int A, B, Confirm, Q;
ConfirmValues(A, B, Confirm);
CA = A;
CB = B;
Q = CA / CB;
Out = CA - Q * CB;
if (Out < 0) {
    Out += abs(CB);
}
//Out = CA % CB;

}




int main() {
  int CA, CB, Out;
  cout << "Modulus Calculator\n";
  cout << "This calculator uses the format 'a' mod 'b'\nNote that all decimal values will be rounded down to the nearest integer\n\n";
  CalculateRemainder(CA, CB, Out);
  cout << "Calculate:  " << CA << " mod " << CB << " = " << Out << "\n\n";
}
