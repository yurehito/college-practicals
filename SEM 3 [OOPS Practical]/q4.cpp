// Question 4:
// Define a class "complex" with two data members "real" and "imag" to represent
// real and imaginary parts of a complex number. Write member functions
// par() : to return the real part
// ipar(): to return the imaginary part
// add() : to add two complex numbers
// mul() : to multiply two complex numbers
// Write constructors with zero, one and two arguments to initialize objects.

#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r=0, double i=0) : real(r), imag(i) {}
    double par() const { return real; }
    double ipar() const { return imag; }
    Complex add(const Complex &o) const { return Complex(real + o.real, imag + o.imag); }
    Complex mul(const Complex &o) const {
        return Complex(real*o.real - imag*o.imag, real*o.imag + imag*o.real);
    }
    void display() const { cout << real << (imag>=0?"+":"") << imag << "i\n"; }
};

int main() {
    Complex a(2,3), b(1,-1);
    cout << "a = "; a.display();
    cout << "b = "; b.display();
    cout << "sum = "; a.add(b).display();
    cout << "product = "; a.mul(b).display();
    return 0;
}
