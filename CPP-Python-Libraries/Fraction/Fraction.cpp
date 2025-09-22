//Replacement for Fraction from fractions in python

#include <iostream>
#include "rational-develop\include\boost\rational.hpp" //needs to be changed for class
using std::cout, std::cin;


int main() {
int a,b;

cout << "Fraction Function for CPP\nEnter value for a: ";
cin >> a;
cout << "\nEnter value for b: ";
cin >> b;
boost::rational<int> r1(a, b);
boost::rational<int> r2(b, a);

auto result = r1 + r2;

cout << r1 << " + " << r2 <<  " = " << result.numerator() << "/" << result.denominator() << "\n";
}
