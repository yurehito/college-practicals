// Question 8:
// Define a class "time" to store time as hour, minute and second, all being integer values.
// Write member functions to display time in standard format. Also overload the ++ and --
// operators to increase and decrease a given time by one second where the minute and hour
// values will have to be updated whenever necessary.

#include <iostream>
#include <iomanip>
using namespace std;

class Time {
    int hour, minute, second;
    void normalize() {
        if (second >= 60) { minute += second / 60; second %= 60; }
        if (second < 0) { int b = (-second + 59)/60; minute -= b; second += b*60; }
        if (minute >= 60) { hour += minute / 60; minute %= 60; }
        if (minute < 0) { int b = (-minute + 59)/60; hour -= b; minute += b*60; }
        hour = (hour % 24 + 24) % 24;
    }
public:
    Time(int h=0,int m=0,int s=0): hour(h), minute(m), second(s) { normalize(); }
    void display() const {
        cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << '\n';
    }
    Time& operator++() { ++second; normalize(); return *this; } // prefix
    Time operator++(int) { Time tmp=*this; ++(*this); return tmp; } // postfix
    Time& operator--() { --second; normalize(); return *this; } // prefix
    Time operator--(int) { Time tmp=*this; --(*this); return tmp; } // postfix
};

int main() {
    Time t(23,59,59);
    t.display();
    ++t; t.display();
    t--; t.display();
    return 0;
}
