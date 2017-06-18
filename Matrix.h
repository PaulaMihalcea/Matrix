//
// Created by Zelethil on 18.06.2017.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

// TODO RES: https://www.programiz.com/cpp-programming/examples/matrix-multiplication

#include <iostream>

using namespace std;


template<class T>
class Matrix {
public:
    Matrix(int r, int c, T v) : rows(r), cols(c) {
        data = new int[r*c];
        size = rows * cols;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
                setValue(i, j, v);
        cout << "Matrix created." << endl;
    }

    ~Matrix() {
        delete[] data;
    }

    bool setValue(int x, int y, T v){
        if (x>=rows || y>=cols || x<0 || y<0){
            cout << "setValue: Invalid x or y" << endl;
            return false;
        }

        data[cols*(x-1)+(y-1)] = v;
        cout << "Value at (" << x+1 << ", " << y+1 << ") set to " << v << "." << endl;
        return true;
    }

    int getValue(int x, int y, T& v) const {
        if (x >= rows || y >= cols || x < 0 || y < 0) {
            cout << "getValue: Invalid x or y" << endl;
            return false;
        }
        v = data[cols*(x-1)+(y-1)];
        cout << "Value at (" << x+1 << ", " << y+1 << "): " << v << "." << endl;
        return true;
    }

    bool getRow(int x) const {
        if (x > rows || x < 0) {
            cout << "getRow: Invalid row number" << endl;
            return false;
        }
        T v;
        for (int j=0; j<cols; j++) {
            getValue(x-1, j, v);
        }
        /*row = new int[cols];
        for (int j=0; j<cols; j++) {
            int value = cols * (x - 1) + j;
            cout << "Value: " << value << endl;
            row[j] = data[value];
            cout << "Column " << j+1 << ": " << row[j] << endl;
        }*/
        return true;
    }

    bool getCol(int y) const {
        if (y > cols || y < 0) {
            cout << "getCol: Invalid column number" << endl;
            return false;
        }
        T v;
        for (int i=0; i<rows; i++) {
            getValue(i, y-1, v);
        }
        return true;
    }

    bool getMatrix() const {
        int i;
        for (i=1; i<=rows; i++) {
            getRow_(i);
            cout << endl;
        }
    }

    int getValue_(int x, int y, T& v) const {
        if (x >= rows || y >= cols || x < 0 || y < 0) {
            cout << "getValue: Invalid x or y" << endl;
            return false;
        }
        v = data[cols*(x-1)+(y-1)];
        cout << v << " ";
        return true;
    }

    bool getRow_(int x) const {
        if (x > rows || x < 0) {
            cout << "getRow: Invalid row number" << endl;
            return false;
        }
        T v;
        for (int j=0; j<cols; j++) {
            getValue_(x-1, j, v);
        }
        /*row = new int[cols];
        for (int j=0; j<cols; j++) {
            int value = cols * (x - 1) + j;
            cout << "Value: " << value << endl;
            row[j] = data[value];
            cout << "Column " << j+1 << ": " << row[j] << endl;
        }*/
        return true;
    }

private:
    const int rows;
    const int cols;
    int size;
    T* data;
};

#endif //MATRIX_MATRIX_H
