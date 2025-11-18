// Question 2:
// Define a structure "employee" with the following specifications.
// empno : integer
// ename : 20 characters
// basic, hra, da : float
// calculate() : a function to compute net pay as basic+hra+da with float return type.
// getdata() : a function to read values for empno, ename, basic, hra, da.
// dispdata() : a function to display all the data on the screen
// Write a main program to test the program.

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct employee {
    int empno;
    char ename[21];
    float basic, hra, da;

    float calculate() const { return basic + hra + da; }

    void getdata() {
        cout << "Emp no: "; cin >> empno;
        cout << "Name: "; cin >> setw(20) >> ename;
        cout << "Basic HRA DA: "; cin >> basic >> hra >> da;
    }

    void dispdata() const {
        cout << "\nEmpno: " << empno << "\nName: " << ename
             << "\nBasic: " << basic << " HRA: " << hra << " DA: " << da
             << "\nNet pay: " << calculate() << endl;
    }
};

int main() {
    employee e;
    e.getdata();
    e.dispdata();
    return 0;
}
