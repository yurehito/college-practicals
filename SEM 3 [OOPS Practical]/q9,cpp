// Question 9:
// Define a class to store matrices. Write suitable friend functions to add and multiply two matrices.

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    int rows, cols;
    vector<vector<int>> a;
public:
    Matrix(int r=0,int c=0): rows(r), cols(c), a(r, vector<int>(c,0)) {}
    void read() {
        cout << "Rows cols: "; cin >> rows >> cols;
        a.assign(rows, vector<int>(cols));
        cout << "Enter elements row-wise:\n";
        for (int i=0;i<rows;++i) for (int j=0;j<cols;++j) cin >> a[i][j];
    }
    void display() const {
        for (int i=0;i<rows;++i) {
            for (int j=0;j<cols;++j) cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
    friend Matrix add(const Matrix &m1, const Matrix &m2) {
        if (m1.rows!=m2.rows || m1.cols!=m2.cols) return Matrix();
        Matrix r(m1.rows, m1.cols);
        for (int i=0;i<m1.rows;++i) for (int j=0;j<m1.cols;++j) r.a[i][j]=m1.a[i][j]+m2.a[i][j];
        return r;
    }
    friend Matrix multiply(const Matrix &m1, const Matrix &m2) {
        if (m1.cols != m2.rows) return Matrix();
        Matrix r(m1.rows, m2.cols);
        for (int i=0;i<r.rows;++i)
            for (int j=0;j<r.cols;++j)
                for (int k=0;k<m1.cols;++k)
                    r.a[i][j] += m1.a[i][k]*m2.a[k][j];
        return r;
    }
};

int main() {
    cout << "Matrix A\n"; Matrix A; A.read();
    cout << "Matrix B\n"; Matrix B; B.read();
    cout << "\nA + B:\n"; add(A,B).display();
    cout << "\nA * B:\n"; multiply(A,B).display();
    return 0;
}
