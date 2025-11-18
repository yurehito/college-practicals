// Question 5:
// Define a class "point" with two data members "xordinate" and "yordinate" to
// represent all points in the two-dimensional plane by storing their
// x-coordinate and y-coordinate values.
// Write member functions:
// dist(): to return the distance of the point from the origin.
// slope(): to return the slope of the line obtained by joining this point with the origin.
// Write constructors with zero, one and two arguments to initialize objects.
// Also write a friend function to compute the distance between two points.

#include <iostream>
#include <cmath>
using namespace std;

class Point {
    double xordinate, yordinate;
public:
    Point(double x=0, double y=0) : xordinate(x), yordinate(y) {}
    double dist() const { return sqrt(xordinate*xordinate + yordinate*yordinate); }
    double slope() const { return (xordinate==0 ? INFINITY : (yordinate / xordinate)); }
    friend double distanceBetween(const Point &p1, const Point &p2) {
        double dx = p1.xordinate - p2.xordinate;
        double dy = p1.yordinate - p2.yordinate;
        return sqrt(dx*dx + dy*dy);
    }
};

int main() {
    Point p1(3,4), p2(0,0);
    cout << "p1 dist from origin: " << p1.dist() << '\n';
    cout << "p1 slope: " << p1.slope() << '\n';
    cout << "Distance between p1 and p2: " << distanceBetween(p1,p2) << '\n';
    return 0;
}
