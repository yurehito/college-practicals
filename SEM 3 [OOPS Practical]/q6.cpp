// Question 6:
// Define a class "string" with the following data members char *p; int size;
// and write member functions to do the following (without using library function)
// and using dynamic memory allocation.
// • Length of the string
// • Compare two strings
// • Copy one string to another
// • Reverse the string
// Write suitable constructors and destructors. Also write a copy constructor for the class.

#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char *p;
    int size;
public:
    MyString() : p(nullptr), size(0) {}
    MyString(const char *s) {
        if (!s) { p=nullptr; size=0; }
        else { size = strlen(s); p = new char[size+1]; strcpy(p, s); }
    }
    MyString(const MyString &other) : size(other.size) {
        if (size>0) { p = new char[size+1]; strcpy(p, other.p); } else p=nullptr;
    }
    ~MyString() { delete[] p; }

    int length() const { return size; }

    int compare(const MyString &other) const {
        if (!p && !other.p) return 0;
        if (!p) return -1;
        if (!other.p) return 1;
        return strcmp(p, other.p);
    }

    void copyFrom(const MyString &other) {
        if (this==&other) return;
        delete[] p;
        size = other.size;
        if (size>0) { p = new char[size+1]; strcpy(p, other.p); } else p=nullptr;
    }

    void reverse() {
        if (!p) return;
        for (int i=0, j=size-1; i<j; ++i, --j) swap(p[i], p[j]);
    }

    const char* c_str() const { return p ? p : ""; }
};

int main() {
    MyString s1("Hello");
    MyString s2(s1);
    cout << "s1: " << s1.c_str() << " len=" << s1.length() << '\n';
    s2.reverse();
    cout << "s2 reversed: " << s2.c_str() << '\n';
    MyString s3;
    s3.copyFrom(s2);
    cout << "s3 copied: " << s3.c_str() << '\n';
    return 0;
}
