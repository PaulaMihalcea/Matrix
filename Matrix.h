//
// Created by Zelethil on 18.06.2017.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Matrix {
public:
    Matrix(int r, int c, T v) : rows(r), cols(c) { // constructor
        size = rows*cols;
        data.reserve(size);
        for (int i=0; i<size; i++) {
            data.push_back(v);
        }
    }

    ~Matrix() { // destructor
        data.erase(data.begin(), data.end());
    }

    int getRows() const { // rows getter
        return rows;
    }

    int getCols() const { // cols getter
        return cols;
    }

    bool getValue(int x, int y, T& v) const { // value getter (use only for single elements of the matrix)
        if (x > rows || y > cols || x <= 0 || y <= 0) {
            cout << "getValue: Invalid x or y" << endl;
            return false;
        }
        v = data[cols*(x-1)+(y-1)];
        cout << "Value at (" << x << ", " << y << "): " << v << "." << endl;
        return true;
    }

    bool setValue(int x, int y, T v){ // value setter (use only for single elements of the matrix)
        if (x > rows || y > cols || x <= 0 || y <= 0){
            cout << "setValue: Invalid x or y" << endl;
            return false;
        }
        data[cols*(x-1)+(y-1)] = v;
        cout << "Value at (" << x << ", " << y << ") set to " << v << "." << endl;
        return true;
    }

    bool getRow(int x) const {  // row getter (use only for single rows of the matrix)
        if (x > rows || x <= 0) {
            cout << "getRow: Invalid row number" << endl;
            return false;
        }
        T v;
        cout << "Row " << x << ": ";
        for (int j=1; j<=cols; j++) {
            getValue_(x, j, v);
            cout << v << " ";
        }
        cout << endl;
        return true;
    }

    bool getCol(int y) const {  // column getter (use only for single columns of the matrix)
        if (y > cols || y <= 0) {
            cout << "getCol: Invalid column number" << endl;
            return false;
        }
        T v;
        cout << "Column " << y << ":" << endl;
        for (int i=1; i<=rows; i++) {
            getValue_(i, y, v);
            cout << v << endl;
        }
        return true;
    }

    void getMatrix() const { // matrix getter
        cout << "Matrix:" << endl;
        T v;
        for (int i=1; i<=rows; i++) {
            for (int j=1; j<=cols; j++) {
                getValue_(i, j, v);
                cout << v << " ";
            }
            cout << endl;
        }
    }

    Matrix<T> operator*(const T& a) {
        for (int i=1; i<=rows; i++)
            for (int j=1; j<=cols; j++){
                T v;
                getValue_(i, j, v);
                v = v * a;
                setValue_(i, j, v);
            }
        getMatrix();
    }

    Matrix<T> operator+(const Matrix<T>& B) { // operator + (sum)
        Matrix<T> C(rows, cols, 0);
        if (rows == B.rows && cols == B.cols) {
            T a;
            T b;
            T c;
            for (int i=1; i <= rows; i++)
                for (int j=1; j <= cols; j++) {
                    getValue_(i, j, a);
                    B.getValue_(i, j, b);
                    c = a + b;
                    C.setValue_(i, j, c);
                }
            C.getMatrix();
        }
        else
            cout << "Number of rows and cols should be the same in both matrices." << endl;
    }

    Matrix<T> operator-(const Matrix<T>& B) { // operator + (sum)
        Matrix<T> C(rows, cols, 0);
        if (rows == B.rows && cols == B.cols) {
            T a;
            T b;
            T c;
            for (int i=1; i <= rows; i++)
                for (int j=1; j <= cols; j++) {
                    getValue_(i, j, a);
                    B.getValue_(i, j, b);
                    c = a - b;
                    C.setValue_(i, j, c);
                }
            C.getMatrix();
        }
        else
            cout << "Number of rows and cols should be the same in both matrices." << endl;
    }

    Matrix<T> operator*(const Matrix<T>& B) { // operator * (multiplication)
        Matrix<T> C(rows, B.cols, 0);
        if (cols == B.rows) {
            T a;
            T b;
            for (int i=1; i <= rows; i++)
                for (int j=1; j <= cols; j++) {
                    T c = 0;
                    for (int k=1; k<=cols; k++) {
                        getValue_(i, k, a);
                        B.getValue_(k, j, b);
                        c += a * b;
                        C.setValue_(i, j, c);
                    }
                }
            C.getMatrix();
        }
        else
            cout << "Number of cols in the first matrix (" << cols << ") should be equal to the number of rows in the second matrix (" << B.rows << ")." << endl;
    }

    Matrix<T> transpose() const { // transpose matrix
        Matrix<T> t(cols, rows, 0);
        for (int i=1; i<=rows; i++)
            for (int j=1; j<=cols; j++) {
                T v;
                getValue_(i, j, v);
                t.setValue_(j, i, v);
            }
        cout << "TRANSPOSE" << endl;
        t.getMatrix();
        return t;
    }

private:
    const int rows;
    const int cols;
    int size;
    vector<T> data;

    bool getValue_(int x, int y, T& v) const { // value getter (no output)
        if (x > rows || y > cols || x <= 0 || y <= 0) {
            return false;
        }
        v = data[cols*(x-1)+(y-1)];
        return true;
    }

    bool setValue_(int x, int y, T v){ // value setter (no output)
        if (x > rows || y > cols || x <= 0 || y <= 0){
            return false;
        }
        data[cols*(x-1)+(y-1)] = v;
        return true;
    }
};

#endif //MATRIX_H
