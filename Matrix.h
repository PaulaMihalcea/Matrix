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

    int getSize() const {
        return size;
    }

    T getValue(int x, int y) const { // value getter
        if (x > rows || y > cols || x <= 0 || y <= 0) {
            cout << "getValue: Invalid x or y" << endl;
            return -1;
        }
        else
            return data[cols*(x-1)+(y-1)];
    }

    T setValue(int x, int y, T v){ // value setter
        if (x > rows || y > cols || x <= 0 || y <= 0){
            cout << "setValue: Invalid x or y" << endl;
            return 1;
        }
        else
            return data[cols*(x-1)+(y-1)] = v;
    }

    bool getRow(int x) const {  // row getter
        if (x > rows || x <= 0) {
            cout << "getRow: Invalid row number" << endl;
            return false;
        }
        T v;
        cout << "Row " << x << ": ";
        for (int j=1; j<=cols; j++) {
            cout << getValue(x, j) << " ";
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
            cout << getValue(i, y) << endl;
        }
        return true;
    }

    void getMatrix() const { // matrix getter
        T v;
        for (int i=1; i<=rows; i++) {
            for (int j=1; j<=cols; j++) {
                cout << getValue(i, j) << " ";
            }
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& B) { // operator + (sum)
        if (this->rows == B.rows && this->cols == B.cols) {
            T a;
            T b;
            T c;
            for (int i=1; i <= rows; i++)
                for (int j=1; j <= cols; j++) {
                    a = getValue(i, j);
                    b = B.getValue(i, j);
                    c = a + b;
                    setValue(i, j, c);
                }
            return *this;
        }
        else
            cout << "Number of rows and cols should be the same for both matrices." << endl;
    }

    Matrix<T> operator-(const Matrix<T>& B) { // operator + (sum)
        if (rows == B.rows && cols == B.cols) {
            T a;
            T b;
            T c;
            for (int i=1; i <= rows; i++)
                for (int j=1; j <= cols; j++) {
                    a = getValue(i, j);
                    b = B.getValue(i, j);
                    c = a - b;
                    setValue(i, j, c);
                }
            return *this;
        }
        else
            cout << "Number of rows and cols should be the same for both matrices." << endl;
    }

    Matrix<T> operator*(const T& a) { // operator * (scalar multiplication)
        T v;
        for (int i=1; i<=rows; i++)
            for (int j=1; j<=cols; j++){
                v = getValue(i, j);
                v = v * a;
                setValue(i, j, v);
            }
        return *this;
    }

    Matrix<T> operator*(const Matrix<T>& B) { // operator * (matrix multiplication)
        Matrix<T> C(rows, B.cols, 0);
        if (cols == B.rows) {
            T a;
            T b;
            for (int i=1; i <= rows; i++)
                for (int j=1; j <= cols; j++) {
                    T c = 0;
                    for (int k=1; k<=cols; k++) {
                        a = getValue(i, k);
                        b = B.getValue(k, j);
                        c += a * b;
                        C.setValue(i, j, c);
                    }
                }
            return C;
        }
        else
            cout << "Number of cols in the first matrix (" << cols << ") should be equal to the number of rows in the second matrix (" << B.rows << ")." << endl;
    }

    Matrix<T> transpose() const { // transpose matrix
        Matrix<T> t(cols, rows, 0);
        for (int i=1; i<=rows; i++)
            for (int j=1; j<=cols; j++) {
                T v = getValue(i, j);
                t.setValue(j, i, v);
            }
        cout << "Transpose matrix:" << endl;
        t.getMatrix();
        return t;
    }

private:
    const int rows;
    const int cols;
    int size;
    vector<T> data;
};

#endif //MATRIX_H
