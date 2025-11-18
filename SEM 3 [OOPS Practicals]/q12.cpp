// Question 12:
// Define an abstract base class printer. Derive three classes laser-printer,
// line-printer and inkjet-printer. The derived classes will have data members
// to store the features of that particular printer. Write pure virtual function
// display() in the base class and redefine it in the derived classes.

#include <iostream>
#include <vector>
using namespace std;

class Printer {
public:
    virtual void display() const = 0;
    virtual ~Printer() = default;
};

class LaserPrinter : public Printer {
    string model;
    int ppm;
public:
    LaserPrinter(string m="", int p=0) : model(m), ppm(p) {}
    void display() const override { cout << "Laser: " << model << " " << ppm << "ppm\n"; }
};

class LinePrinter : public Printer {
    string name;
public:
    LinePrinter(string n="") : name(n) {}
    void display() const override { cout << "LinePrinter: " << name << '\n'; }
};

class InkjetPrinter : public Printer {
    string vendor;
public:
    InkjetPrinter(string v="") : vendor(v) {}
    void display() const override { cout << "Inkjet: " << vendor << '\n'; }
};

int main() {
    vector<Printer*> v;
    v.push_back(new LaserPrinter("LX100", 20));
    v.push_back(new LinePrinter("LP-1"));
    v.push_back(new InkjetPrinter("InkPro"));
    for (auto p : v) p->display();
    for (auto p : v) delete p;
    return 0;
}
