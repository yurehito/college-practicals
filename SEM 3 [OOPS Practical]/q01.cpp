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
    double a, b, c;
public:
    triangle(double x=0, double y=0, double z=0) : a(x), b(y), c(z) {}
    bool isIsosceles() const { return (a==b) || (b==c) || (a==c); }
    bool isEquilateral() const { return (a==b) && (b==c); }
};

int main() {
    double x,y,z;
    cout << "Enter three sides: ";
    if(!(cin>>x>>y>>z)) return 0;
    triangle t(x,y,z);
    if (t.isEquilateral()) cout << "Equilateral\n";
    else if (t.isIsosceles()) cout << "Isosceles\n";
    else cout << "Scalene\n";
    return 0;
}
