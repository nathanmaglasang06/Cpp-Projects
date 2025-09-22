//Replacement for gcd from sympy.gcd in python

#include <iostream>
#include <numeric>
using std::cout, std::cin;

int main(){
int a,b;

cout << "GCD Function CPP\nEnter value for a: ";
cin >> a;
cout << "\nEnter value for b: ";
cin >> b;
cout << "\ngcd(" << a << ", " << b << ") = " << std::gcd(a, b) << "\n";
}
