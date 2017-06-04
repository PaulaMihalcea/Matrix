//
// Created by Zelethil on 04.06.2017.
//

#ifndef MATRIX_MATRIXTEMPLATE_H
#define MATRIX_MATRIXTEMPLATE_H

// TODO RES: https://www.programiz.com/cpp-programming/examples/matrix-multiplication


template<class T>
class MatrixTemplate {
public:
    MatrixTemplate(int x, int y) : rows{x}, cols{y} { // constructor
        data = new T[x][y]; // multidimensional array
        // TODO implement code for matrix initialization
    };
    virtual ~MatrixTemplate() { // destructor
        // TODO implement
    }

    int getRows() const { // getter for rows
        return rows;
    };

    int getCols() const { // getter for cols
        return cols;
    };

    T getValue(int x, int y, T& v) const { // getter for value at coords x, y
        // TODO implement
    };

    bool setValue(int x, int y, T v) { // setter for value at coords x, y
        // TODO implement
    };


private:
    const int rows;
    const int cols;
    T* data;
};


#endif //MATRIX_MATRIXTEMPLATE_H