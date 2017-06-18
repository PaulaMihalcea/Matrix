#include <iostream>
#include "Matrix.h"

int main() {

    Matrix<int> a(2, 2, 3);
    Matrix<int> b(2, 2, 1);
    a.getMatrix();
    b.getMatrix();
    Matrix<int> c(2, 2, 0);
    cout << a.getRows() << endl;
    cout << a.getCols() << endl;
    cout << b.getRows() << endl;
    cout << b.getCols() << endl;
    a.getMatrix();
    a+b;
    a.getMatrix();


    /*cout << endl;
    cout << "--------" << endl;
    cout << endl;


    cout << "MULTIPLICATION" << endl << endl;
    Matrix<int> c=a*b;

    Matrix<int> a2(2, 2, 1);
    Matrix<int> b2(2, 2, 1);
    Matrix<int> c2=a2-b2;*/

    return 0;
}