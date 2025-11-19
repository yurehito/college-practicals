// Question 1:
// Define a class named "triangle" to represent a triangle using the lengths
// of the three sides. Write a constructor to initialize objects of this class,
// given the lengths of the sides. Also write member functions to check
// (a) if a triangle is isosceles
// (b) if a triangle is equilateral
// Write a main function to test your functions.

#include <iostream>
using namespace std;

class triangle {
    float a, b, c;
public:
    triangle(float x, float y, float z) {
        a = x;
        b = y;
        c = z;
    }

    bool isIsosceles() {
        return (a == b) || (b == c) || (a == c);
    }

    bool isEquilateral() {
        return (a == b) && (b == c);
    }
};

int main() {
    float x, y, z;

    cout << "Enter three sides: ";
    cin >> x >> y >> z;

    triangle t(x, y, z);

    if (t.isEquilateral())
        cout << "Equilateral\n";
    else if (t.isIsosceles())
        cout << "Isosceles\n";
    else
        cout << "Scalene\n";

    return 0;
}
