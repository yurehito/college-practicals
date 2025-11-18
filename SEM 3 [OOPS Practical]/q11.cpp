// Question 11:
// Define a class student with the following specification:
// rollno : integer
// sname : 20 characters
// Derive two classes arst and scst. The class arst will represent students belonging to
// arts stream and the class scst will represent students belonging to science stream.
// The arst class will have additional data members ph, hs, en and as to store marks
// obtained by a student in Philosophy, History, English and Assamese.
// The class scst will have additional data members sph, ch, ma and en to store marks
// obtained in Physics, Chemistry, Mathematics and English.
// Write the following member functions in the classes arst and scst;
// ctotal() : a function to calculate the total marks obtained by a student;
// takedata() : a function to accept values of the data members and showdata() :
// a function to display the marks sheet of a student.

#include <iostream>
#include <iomanip>
using namespace std;

class student {
protected:
    int rollno;
    char sname[21];
public:
    student() : rollno(0) { sname[0]='\0'; }
    virtual void takedata() {
        cout << "Roll no: "; cin >> rollno;
        cout << "Name: "; cin >> setw(20) >> sname;
    }
    virtual void showdata() const {
        cout << "Roll: " << rollno << " Name: " << sname << '\n';
    }
    virtual ~student() = default;
};

class arst : public student {
    int ph, hs, en, as;
public:
    arst() : ph(0), hs(0), en(0), as(0) {}
    void takedata() override {
        student::takedata();
        cout << "Enter Philosophy History English Assamese: ";
        cin >> ph >> hs >> en >> as;
    }
    int ctotal() const { return ph+hs+en+as; }
    void showdata() const override {
        student::showdata();
        cout << "Marks Ph:" << ph << " Hs:" << hs << " En:" << en << " As:" << as
             << " Total:" << ctotal() << '\n';
    }
};

class scst : public student {
    int phy, ch, ma, en;
public:
    scst() : phy(0), ch(0), ma(0), en(0) {}
    void takedata() override {
        student::takedata();
        cout << "Enter Physics Chemistry Mathematics English: ";
        cin >> phy >> ch >> ma >> en;
    }
    int ctotal() const { return phy+ch+ma+en; }
    void showdata() const override {
        student::showdata();
        cout << "Marks Phy:" << phy << " Ch:" << ch << " Ma:" << ma << " En:" << en
             << " Total:" << ctotal() << '\n';
    }
};

int main() {
    cout << "Arts student:\n"; arst a; a.takedata();
    cout << "Science student:\n"; scst s; s.takedata();

    cout << "\n--- Mark sheets ---\n";
    a.showdata();
    s.showdata();
    return 0;
}
