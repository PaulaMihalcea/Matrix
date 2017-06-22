/* MATRIX
 * by Paula Mihalcea
 *
 * UniFi - Ingegneria Informatica
 * Laboratorio di programmazione
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<class T>
class Matrix {
public:
    Matrix(int r, int c, T v) throw (out_of_range) : rows(r), cols(c) { // constructor
        try {
            if (rows<=0 || cols <=0) {
                throw out_of_range("Invalid x or y.");
            }
            else {
                data.reserve(rows*cols);
                for (int i=0; i<rows*cols; i++) {
                    data.push_back(v);
                }
            }
        } catch (const out_of_range& e) {
            cerr << e.what() << endl;
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

    T getValue(int x, int y) const throw(out_of_range) { // value getter
        try {
            if (x > rows || y > cols || x <= 0 || y <= 0)
                throw out_of_range("Invalid x or y.");
            else
                return data[cols*(x-1)+(y-1)];
        } catch (const out_of_range& e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }

    void setValue(int x, int y, T v) throw(out_of_range) { // value setter
        try {
            if (x > rows || y > cols || x <= 0 || y <= 0) {
                throw out_of_range("Invalid x or y.");
            }
            else
                data[cols * (x - 1) + (y - 1)] = v;
        } catch (const out_of_range& e) {
            cerr << e.what() << endl;
        }
    }

    Matrix<T> getRow(int x) const throw(out_of_range) {  // row getter
        try {
            if (x > rows || x <= 0)
                throw out_of_range("Invalid x.");
            else {
                Matrix<T> m(1, cols, 0);
                for (int j = 1; j <= cols; j++) {
                    m.setValue(1, j, getValue(x, j));
                }
                return m;
            }
        } catch (out_of_range &e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }

    Matrix<T> getCol(int y) const throw(out_of_range) {  // column getter
        try {
            if (y > cols || y <= 0)
                throw out_of_range("Invalid y.");
            else {
                Matrix<T> m(rows, 1, 0);
                for (int i = 1; i <= rows; i++) {
                    m.setValue(i, 1, getValue(i, y));
                }
                return m;
            }
        } catch (out_of_range &e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }

    friend ostream& operator<<(ostream &output, const Matrix<T>& m) { // operator << [cout << matrix or cout <<
        // matrix.function()]
            for (int i = 1; i <= m.rows; i++) {
                for (int j = 1; j <= m.cols; j++) {
                    output << m.getValue(i, j) << " ";
                }
                cout << endl;
            }
            return output;
    }

    void operator=(const Matrix<T>& B) throw(out_of_range) { // operator =
        try {
            if (this->rows == B.rows && this->cols == B.cols) {
                T b;
                for (int i = 1; i <= rows; i++)
                    for (int j = 1; j <= cols; j++) {
                        b = B.getValue(i, j);
                        setValue(i, j, b);
                    }
            } else
                throw out_of_range("Number of rows and cols should be the same for both matrices.");
        } catch (out_of_range &e) {
            cerr << e.what() << endl;
        };
    }

    Matrix<T> operator+(const Matrix<T>& B) throw(out_of_range) { // operator + (sum)
        try {
            if (this->rows == B.rows && this->cols == B.cols) {
                T a;
                T b;
                T c;
                for (int i = 1; i <= rows; i++)
                    for (int j = 1; j <= cols; j++) {
                        a = getValue(i, j);
                        b = B.getValue(i, j);
                        c = a + b;
                        setValue(i, j, c);
                    }
                return *this;
            }
            else
                throw out_of_range("Number of rows and cols should be the same for both matrices.");
        } catch (out_of_range &e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }

    Matrix<T> operator-(const Matrix<T>& B) throw(out_of_range) { // operator - (difference)
        try {
            if (this->rows == B.rows && this->cols == B.cols) {
                T a;
                T b;
                T c;
                for (int i = 1; i <= rows; i++)
                    for (int j = 1; j <= cols; j++) {
                        a = getValue(i, j);
                        b = B.getValue(i, j);
                        c = a - b;
                        setValue(i, j, c);
                    }
                return *this;
            }
            else
                throw out_of_range("Number of rows and cols should be the same for both matrices.");
        } catch (out_of_range &e) {
            cerr << e.what() << endl;
            exit(-1);
        }
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

    Matrix<T> operator*(const Matrix<T>& B) throw(out_of_range) { // operator * (matrix multiplication)
        try {
            Matrix<T> C(rows, B.cols, 0);
            if (cols == B.rows) {
                T a;
                T b;
                for (int i = 1; i <= rows; i++)
                    for (int j = 1; j <= cols; j++) {
                        T c = 0;
                        for (int k = 1; k <= cols; k++) {
                            a = getValue(i, k);
                            b = B.getValue(k, j);
                            c += a * b;
                            C.setValue(i, j, c);
                        }
                    }
                return C;
            } else
                throw out_of_range(
                        "Number of cols in the first matrix should be equal to the number of rows in the second matrix.");
        } catch (out_of_range &e) {
            cerr << e.what() << endl;
            exit(-1);
        }
    }

    Matrix<T> transpose() const { // transpose matrix
        Matrix<T> t(cols, rows, 0);
        for (int i=1; i<=rows; i++)
            for (int j=1; j<=cols; j++) {
                T v = getValue(i, j);
                t.setValue(j, i, v);
            }
        cout << "Transpose matrix:" << endl << t << endl;
        return t;
    }

private:
    const int rows;
    const int cols;
    vector<T> data;
};

#endif //MATRIX_H
