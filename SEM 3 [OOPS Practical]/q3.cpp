// Question 3:
// Define a class "circle" to represent circles. Add a data member radius to
// store the radius of a circle. Write member functions area() and perimeter()
// to compute the area and perimeter of a circle.

#include <iostream>
#include <cmath>
using namespace std;

class circle {
    double r;
public:
    circle(double radius=0) : r(radius) {}
    double area() const { return M_PI * r * r; }
    double perimeter() const { return 2.0 * M_PI * r; }
};

int main() {
    double rad;
    cout << "Radius: "; cin >> rad;
    circle c(rad);
    cout << "Area: " << c.area() << "\nPerimeter: " << c.perimeter() << '\n';
    return 0;
}
