//
// Created by Zelethil on 18.06.2017.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

// TODO Classi template per matrici con implementazione di operazioni come prodotto e trasposta, oltre che selezione di righe e colonne (usare Factory per creare gli oggetti)

// TODO void functions (instead of boolean)

#include <iostream>
#include <vector>

using namespace std;


template<class T>
class Matrix {
public:
    Matrix(int r, int c, T v) : rows(r), cols(c) {
        size = rows*cols;
        for (int i=0; i<size; i++) {
            data.push_back(v);
        }
        cout << "Matrix created." << endl;
        getMatrix();
    }

    ~Matrix() {
        data.erase(data.begin(), data.end());
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    bool setValue(int x, int y, T v){
        if (x > rows || y > cols || x <= 0 || y <= 0){
            cout << "setValue: Invalid x or y" << endl;
            return false;
        }
        data[cols*(x-1)+(y-1)] = v;
        cout << "Value at (" << x << ", " << y << ") set to " << v << "." << endl;
        return true;
    }

    bool getValue(int x, int y, T& v) const {
        if (x > rows || y > cols || x <= 0 || y <= 0) {
            cout << "getValue: Invalid x or y" << endl;
            return false;
        }
        v = data[cols*(x-1)+(y-1)];
        cout << "Value at (" << x << ", " << y << "): " << v << "." << endl;
        return true;
    }

    bool getRow(int x) const {
        if (x > rows || x <= 0) {
            cout << "getRow: Invalid row number" << endl;
            return false;
        }
        T v;
        cout << "Row " << x << ": ";
        for (int j=1; j<=cols; j++) {
            getValue_(x, j, v);
        }
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
        cout << "Matrix:" << endl;
        for (int i=1; i<=rows; i++) {
            getRow_(i);
            cout << endl;
        }
    }

    bool getValue_(int x, int y, T& v) const {
        if (x > rows || y > cols || x <= 0 || y <= 0) {
            cout << "getValue: Invalid x or y" << endl;
            return false;
        }
        v = data[cols*(x-1)+(y-1)];
        cout << v << " ";
        return true;
    }

    bool getRow_(int x) const {
        if (x > rows || x <= 0) {
            cout << "getRow: Invalid row number" << endl;
            return false;
        }
        T v;
        for (int j=1; j<=cols; j++) {
            getValue_(x, j, v);
        }
        return true;
    }

    Matrix<T> transpose() const {
        Matrix<T> tr(rows, cols, 0);
        for (int i=1; i<=rows; i++)
            for (int j=1; j<=cols; j++) {
                T v;
                //this->getValue(i, j, v);
                //tr.setValue(i, j, v);
            }
        return tr;
    }

private:
    const int rows;
    const int cols;
    int size;
    vector<T> data;
};

#endif //MATRIX_MATRIX_H
