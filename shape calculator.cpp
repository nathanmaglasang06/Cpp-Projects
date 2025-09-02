#include <iostream>
#include <string>
#include <cmath>
template <typename T>
auto sqr(T x) { return x * x; }
using namespace std;

void Rectangle() {
int LengthR, WidthR, AreaR, PerimeterR;
cout  << "\nRectangle Calculation\n";
cout << "What is the length of the rectangle: \n";
cin >> LengthR;
cout << "What is the width of the rectangle: \n";
cin >> WidthR;
AreaR = LengthR * WidthR;
PerimeterR = (2 * LengthR)+(2 * WidthR);
cout << "Your Rectangle has the following values: \nArea: " << AreaR << "\nPerimeter: " << PerimeterR << "\nWould you like to do another shape (1) or exit (2)";
int ExitStatus = 0;
cin >> ExitStatus;
if (ExitStatus == 2) {
    cout << "Thanks for using";
    exit(0);
} else {

}

}
void Square() {
int SideS, AreaS, PerimeterS;
cout  << "\nSquare Calculation\n";
cout << "What is the side length of the square: \n";
cin >> SideS;
AreaS = sqr(SideS);
PerimeterS = SideS * 4;
cout << "Your Square has the following values: \nArea: " << AreaS << "\nPerimeter: " << PerimeterS << "\nWould you like to do another shape (1) or exit (2)";
int ExitStatus = 0;
cin >> ExitStatus;
if (ExitStatus == 2) {
    cout << "Thanks for using";
    exit(0);
} else {

}

}
void Triangle() {
int BaseWidthT, HeightT, TriangleType;
float AreaT, PerimeterT;
cout  << "\nTriangle Calculation\n";
cout << "What is the base width of the triangle: \n";
cin >> BaseWidthT;
cout << "What is the height of the triangle: \n";
cin >> HeightT;
AreaT = (float)0.5*(BaseWidthT * HeightT);
cout << "What type of triangle is it: \n1. Right\n2. Isosceles\n3.Equilateral";
cin >> TriangleType;
if (TriangleType == 1) {
PerimeterT = (float)((BaseWidthT + HeightT)+sqrt(sqr(BaseWidthT)+sqr(HeightT)));
} else if (TriangleType == 2) {
PerimeterT = (float)(BaseWidthT+(2*(sqrt(sqr(HeightT) + sqr(BaseWidthT / 2)))));
} else if (TriangleType == 3) {
PerimeterT = (float)(3 * BaseWidthT);
} else {
cout << "Error: Invalid Selection, Exiting";
exit(0);
}
cout << "Your Triangle has the following values: \nArea: " << AreaT << "\nPerimeter: " << PerimeterT << "\nWould you like to do another shape (1) or exit (2)";
int ExitStatus = 0;
cin >> ExitStatus;
if (ExitStatus == 2) {
    cout << "Thanks for using";
    exit(0);
} else {

}
}

int main() {
bool Continue = true;

cout << "Shape Calculator\n\n";

while (Continue) {
    cout << "Please choose a shape below to begin:\n\n1. Rectangle\n2. Square\n3. Triangle\n0. Exit\n\nYour Shape:  ";
    int UserShape;
    cin >> UserShape;
    switch(UserShape) {
    case 1:
        Rectangle();
        break;
    case 2:
        Square();
        break;
    case 3:
        Triangle();
        break;
    case 0:
        Continue = false;
        break;


    default:
        cout  << "Please choose an integer value that correlates with the shapes listed above";
    }
}





}
