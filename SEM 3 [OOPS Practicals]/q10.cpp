// Question 10:
// Write a class-based program implementing static members.

#include <iostream>
using namespace std;

class Counter {
    int id;
    static int count;
public:
    Counter() { id = ++count; }
    int getID() const { return id; }
    static int getCount() { return count; }
};

int Counter::count = 0;

int main() {
    Counter a, b, c;
    cout << "IDs: " << a.getID() << ", " << b.getID() << ", " << c.getID() << '\n';
    cout << "Total objects: " << Counter::getCount() << '\n';
    return 0;
}
