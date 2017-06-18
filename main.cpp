#include <iostream>
#include "Matrix.h"

int main() {

    Matrix<int> m(4, 3, 0);
    m.setValue(1, 1, 1);
    m.setValue(1, 2, 2);
    m.setValue(1, 3, 3);
    m.setValue(2, 1, 5);
    m.setValue(2, 2, 6);
    m.setValue(2, 3, 7);
    m.setValue(3, 1, 9);
    m.setValue(3, 2, 10);
    m.setValue(3, 3, 11);
    m.setValue(4, 1, 13);
    m.setValue(4, 2, 14);
    m.setValue(4, 3, 15);

    cout << "--------" << endl;

    m.getMatrix();
    m.getRow(1);
    m.getCol(2);

    cout << "--------" << endl;

    Matrix<int> t = m.transpose();
    t*2;

    cout << endl;
    cout << "--------" << endl;
    cout << endl;

    Matrix<int> a(1, 3, 0);
    Matrix<int> b(3, 1, 0);
    a.setValue(1, 1, 1);
    a.setValue(1, 2, 2);
    a.setValue(1, 3, 3);
    b.setValue(1, 1, 7);
    b.setValue(2, 1, 8);
    b.setValue(3, 1, 9);
    a.getMatrix();
    b.getMatrix();
    cout << "MULTIPLICATION" << endl << endl;
    Matrix<int> c=a*b;

    Matrix<int> a2(2, 2, 1);
    Matrix<int> b2(2, 2, 1);
    Matrix<int> c2=a2-b2;

    return 0;
}