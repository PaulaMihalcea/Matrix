#include <iostream>
#include "Matrix.h"

int main() {

    Matrix<int> m(3, 3, 0);

    m.setValue(0, 0, 1);
    m.setValue(0, 1, 2);
    //m.setValue(0, 2, 3);
    //m.setValue(0, 3, 4);
    m.setValue(1, 0, 5);
    m.setValue(1, 1, 6);
    /*m.setValue(1, 2, 7);
    m.setValue(1, 3, 8);
    m.setValue(2, 0, 9);
    m.setValue(2, 1, 10);
    m.setValue(2, 2, 11);
    m.setValue(2, 3, 12);
    m.setValue(3, 0, 13);
    m.setValue(3, 1, 14);
    m.setValue(3, 2, 15);
    m.setValue(3, 3, 16);*/
    int v;
    //m.getValue(1, 1, v);

    //int *row;
    //m.getRow(3);
    //m.getCol(3);
    m.getMatrix();
    //cout << m.getCols() << endl;

    /*Matrix<int> sm2(5, 4);
    int value2 = 1;
    sm2.getValue(2, 3, value2);
    cout << "value2 should be 0: " << value2 << endl;

    Matrix<int> sm3(5, 4);
    sm3.setValue(2, 3, 5);
    int value3 = 0;
    sm3.getValue(2, 3, value3);*/

    return 0;
}