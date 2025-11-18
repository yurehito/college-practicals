// Question 7:
// For the class "complex" defined in 4 above, overload the <<, >>, + and * operators
// in the usual sense. Also overload the unary – operator.

#include <iostream>
using namespace std;

class Complex {
public:
    double r, i;
    Complex(double rr=0, double ii=0) : r(rr), i(ii) {}
    Complex operator+(const Complex &o) const { return Complex(r+o.r, i+o.i); }
    Complex operator*(const Complex &o) const { return Complex(r*o.r - i*o.i, r*o.i + i*o.r); }
    Complex operator-() const { return Complex(-r, -i); }

    friend ostream& operator<<(ostream &os, const Complex &c) {
        os << c.r << (c.i>=0?"+":"") << c.i << "i";
        return os;
    }
    friend istream& operator>>(istream &is, Complex &c) {
        is >> c.r >> c.i;
        return is;
    }
};

int main() {
    Complex a(1,2), b;
    cout << "Enter real and imag for b (two numbers): ";
    cin >> b;
    cout << "a = " << a << "\nb = " << b << "\na+b = " << (a+b) << "\na*b = " << (a*b) << "\n- a = " << -a << '\n';
    return 0;
}
