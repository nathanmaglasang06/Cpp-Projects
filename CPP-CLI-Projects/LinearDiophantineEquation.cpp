#include <iostream>

#include <tuple>

#include <algorithm>

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

tuple<i64,i64,i64> ext_gcd(i64 a, i64 b) {
    if (b == 0) {
        i64 g = llabs(a);
        i64 x = (a >= 0 ? 1 : -1);
        i64 y = 0;
        return {g, x, y};
    }
    i64 g, x1, y1;
    tie(g, x1, y1) = ext_gcd(b, a % b);    i64 x = y1;
    i64 y = x1 - (a / b) * y1;
    return {g, x, y};
}

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
void ExtendedEuclideanAlgorithm(int & EA, int & EB, int & EC, int & D, bool & Sol, int &X, int &Y) {
  int A, B, C, Confirm, Q, X1, Y1;
  ConfirmValues(A, B, C, Confirm);
  EA = A;
  EB = B;
  EC = C;

  i64 a = A, b = B, c = C;
  i64 x0, y0, g;

  tie(g, x0, y0) = ext_gcd(a, b);


  D = static_cast<int>(g);

  if (c % g != 0) {
    Sol = false;
    X = 0; Y = 0;
    return;

  }

  Sol = true;
  i64 k = c / g;
  i64 px = x0 * k;
  i64 py = y0 * k;


  X = static_cast<int>(px);
  Y = static_cast<int>(py);

}

int main() {
    cin.tie(nullptr);

    int a, b, c, d, x, y;
    bool Sol;

    cout << "Linear Diophantine Calculator\n"
         << "Format: a*x + b*y = c\n\n";

    ExtendedEuclideanAlgorithm(a, b, c, d, Sol, x, y);

    cout << "\nInputs: a=" << a << "  b=" << b << "  c=" << c << "\n\n";
    cout << "gcd(a,b) = " << d << "\n\n";

    if (!Sol) {
        cout << "No solution because gcd(a,b) does not divide c.\n\n";
        return 0;
    }

    cout << "One solution: x=" << x << "  y=" << y << "\n";
    cout << "General solution:\n";
    cout << "  x = " << x << " + " << (b / d) << "k\n";
    cout << "  y = " << y << " - " << (a / d) << "k\n";

std::vector<std::pair<double,double>> pts;
for (int t = -200; t <= 200; ++t) {
    double xi = x + (b / d) * t;
    double yi = y - (a / d) * t;
    pts.emplace_back(xi, yi);
}

double xmin = x + (b / d) * (-25);
double xmax = x + (b / d) * (25);

// Guard b == 0 (vertical line)
bool vertical = (b == 0);
double y1 = 0.0, y2 = 0.0;
if (!vertical) {
    y1 = (double(c) - double(a) * xmin) / double(b);
    y2 = (double(c) - double(a) * xmax) / double(b);
}

FILE* gp = _popen("gnuplot -persist", "w");
if (gp) {
    fprintf(gp, "set title 'Integer solutions to a*x + b*y = c'\n");
    fprintf(gp, "set xlabel 'x'\nset ylabel 'y'\nset grid\n");

    if (!vertical) {
        fprintf(gp, "plot '-' with lines title 'ax+by=c', "
                    "'-' with points pt 7 ps 0.1 lc rgb 'red' title 'integer solutions'\n");
        fprintf(gp, "%f %f\n%f %f\n", xmin, y1, xmax, y2);
        fprintf(gp, "e\n");
    } else {
        double xv = double(c) / double(a);
        fprintf(gp, "plot '-' with lines title 'ax+by=c', "
                    "'-' with points pt 7 ps 1.5 lc rgb 'red' title 'integer solutions'\n");
        fprintf(gp, "%f %f\n%f %f\n", xv, -1000.0, xv, 1000.0);
        fprintf(gp, "e\n");
    }

    for (auto& p : pts) fprintf(gp, "%f %f\n", p.first, p.second);
    fprintf(gp, "e\n");
    fflush(gp);
    _pclose(gp);
} else {
    std::cout << "\n[Plot skipped: could not start gnuplot. Is it installed and in PATH?]\n";
}



    return 0;
}
