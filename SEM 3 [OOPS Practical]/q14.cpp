// Question 14:
// Write an interactive program to compute square root of a number. The input value
// must be tested for validity. If it is negative, the user defined function my_sqrt()
// should raise an exception.

#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

double my_sqrt(double x) {
    if (x < 0) throw runtime_error("Negative input for square root");
    return sqrt(x);
}

int main() {
    double v;
    cout << "Enter number: "; cin >> v;
    try {
        cout << "Square root = " << my_sqrt(v) << '\n';
    } catch (const exception &e) {
        cout << "Error: " << e.what() << '\n';
    }
    return 0;
}
