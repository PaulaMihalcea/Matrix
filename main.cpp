#include <iostream>
#include "Matrix.h"

int main() {

    Matrix<int> m(4, 3, 0);
    int v;
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

    cout << "-------" << endl;

    m.getRow(1);
    m.getMatrix();

    //m.setValue(0, 0, 1);
    //m.getMatrix();
    /*m.setValue(0, 1, 2);
    //m.setValue(0, 2, 3);
    //m.setValue(0, 3, 4);
    m.setValue(1, 0, 5);
    m.setValue(1, 1, 6);
    m.getMatrix();*/

    return 0;
}