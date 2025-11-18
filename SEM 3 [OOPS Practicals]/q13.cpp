// Question 13:
// Define an abstract base class figure and add to it pure virtual functions
// display() : to display a figure
// get() : to input parameters of the figure
// area() : to compute the area of a figure
// perimeter() : to compute the perimeter of a figure.
// Derive three classes circle, rectangle and triangle from it. A circle is to be
// represented by its radius, rectangle by its length and breadth and triangle by
// the lengths of its sides. Write a main function and write necessary statements
// to achieve run time polymorphism.

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Figure {
public:
    virtual void get() = 0;
    virtual void display() const = 0;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Figure() = default;
};

class Circle : public Figure {
    double r;
public:
    Circle(double rr=0): r(rr) {}
    void get() override { cout << "Radius: "; cin >> r; }
    double area() const override { return M_PI * r * r; }
    double perimeter() const override { return 2*M_PI*r; }
    void display() const override { cout << "Circle r="<<r<<" area="<<area()<<" per="<<perimeter()<<"\n"; }
};

class Rectangle : public Figure {
    double l,b;
public:
    Rectangle(double ll=0,double bb=0): l(ll), b(bb) {}
    void get() override { cout << "Length Breadth: "; cin >> l >> b; }
    double area() const override { return l*b; }
    double perimeter() const override { return 2*(l+b); }
    void display() const override { cout << "Rect L="<<l<<" B="<<b<<" area="<<area()<<" per="<<perimeter()<<"\n"; }
};

class Triangle : public Figure {
    double a,b,c;
public:
    Triangle(double aa=0,double bb=0,double cc=0): a(aa), b(bb), c(cc) {}
    void get() override { cout << "Sides a b c: "; cin >> a >> b >> c; }
    double perimeter() const override { return a+b+c; }
    double area() const override {
        double s = perimeter()/2;
        if (s<=a || s<=b || s<=c) return 0.0;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    void display() const override { cout << "Tri a="<<a<<","<<b<<","<<c<<" area="<<area()<<" per="<<perimeter()<<"\n"; }
};

int main() {
    vector<Figure*> figs;
    figs.push_back(new Circle());
    figs.push_back(new Rectangle());
    figs.push_back(new Triangle());
    cout << "Enter data for each figure:\n";
    for (auto f : figs) f->get();
    cout << "\nResults:\n";
    for (auto f : figs) f->display();
    for (auto f : figs) delete f;
    return 0;
}
