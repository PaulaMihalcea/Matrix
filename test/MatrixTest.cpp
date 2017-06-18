#include "gtest/gtest.h"

#include "../Matrix.h"

TEST(Matrix, DefaultConstructor) { // DEFAULT CONSTRUCTOR
    Matrix<int> m(4, 3, 0); // matrix initialised to all zeros
    cout << "Matrix: " << endl;
    m.getMatrix();

    for (int i=1; i<=m.getRows(); i++) {
        for (int j=1; j<=m.getCols(); j++)
            ASSERT_EQ(0, m.getValue(i, j)); // value in the matrix; should be zero
    }
}

TEST(Matrix, TestSetValue) { // SET VALUE
    Matrix<int> m(4, 3, 0);

    /* MATRIX (4x3)
     *  1    2   3
     *  5    6   7
     *  9   10  11
     * 13   14  15
    */

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

    cout << "Matrix: " << endl;
    m.getMatrix();
}

TEST(Matrix, TestGetValue) { // GET VALUE
    Matrix<int> m(2, 2, 1); // 2x2 matrix initialised to all ones

    ASSERT_EQ(1, m.getValue(1, 1)); // element 1,1
    ASSERT_EQ(1, m.getValue(1, 2)); // element 1,2
    ASSERT_EQ(1, m.getValue(2, 1)); // element 2,1
    ASSERT_EQ(1, m.getValue(2, 2)); // element 2,2
    cout << endl;
    ASSERT_EQ(-1, m.getValue(0, 1)); // invalid row number; -1 stands for error
    ASSERT_EQ(-1, m.getValue(5, 1)); // invalid row number
    ASSERT_EQ(-1, m.getValue(0, 1)); // invalid col number
    ASSERT_EQ(-1, m.getValue(1, 4)); // invalid col number
}

TEST(Matrix, TestGetRows) { // GET ROWS
    Matrix<int> m(10, 6, 0); // 10x6 matrix

    ASSERT_EQ(10, m.getRows());
}

TEST(Matrix, TestGetCols) { // GET COLS
    Matrix<int> m(10, 8, 0); // 10x6 matrix

    ASSERT_EQ(8, m.getCols());
}

TEST(Matrix, GetSize) { // GET SIZE
    Matrix<int> m(13, 7, 0); // 10x6 matrix

    ASSERT_EQ(91, m.getSize());
}

TEST(Matrix, GetRow) { // GET ROW
    Matrix<int> m(2, 3, 0);
    m.setValue(1, 1, 1);
    m.setValue(1, 2, 2);
    m.setValue(1, 3, 3);
    m.setValue(2, 1, 1);
    m.setValue(2, 1, 1);
    m.setValue(2, 1, 1);

    ASSERT_TRUE(m.getRow(1));
    ASSERT_TRUE(m.getRow(2));
    ASSERT_FALSE(m.getRow(0));
    ASSERT_FALSE(m.getRow(5));
    ASSERT_FALSE(m.getRow(-60));
}

TEST(Matrix, GetCol) { // GET COL
    Matrix<int> m(1, 3, 0);
    m.setValue(1, 1, 1);
    m.setValue(1, 2, 2);
    m.setValue(1, 3, 3);

    ASSERT_TRUE(m.getCol(1));
    ASSERT_TRUE(m.getCol(2));
    ASSERT_TRUE(m.getCol(3));
    ASSERT_FALSE(m.getCol(0));
    ASSERT_FALSE(m.getCol(5));
    ASSERT_FALSE(m.getCol(-60));
}

TEST(Matrix, TestSum) { // OPERATOR + (sum)
    Matrix<int> a(2, 2, 3); // 2x2 matrix of threes
    Matrix<int> b(2, 2, 1); // 2x2 matrix of ones
    a+b; // a should now be all fours

    for (int i=1; i<=a.getRows(); i++) {
        for (int j=1; j<=a.getCols(); j++)
            ASSERT_EQ(4, a.getValue(i, j));
    }
}

TEST(Matrix, TestSub) { // OPERATOR - (subtraction)
    Matrix<int> a(2, 2, 3); // 2x2 matrix of threes
    Matrix<int> b(2, 2, 1); // 2x2 matrix of ones
    a-b; // a should now be all twos

    for (int i=1; i<=a.getRows(); i++) {
        for (int j=1; j<=a.getCols(); j++)
            ASSERT_EQ(2, a.getValue(i, j));
    }
}

TEST(Matrix, TestTranspose) {

}

/*TEST(Matrix, TestMult1) { // OPERATOR * (scalar multiplication)
    Matrix<int> m(2, 2, 3);
    cout << "SCALAR MULTIPLICATION" << endl;
    m.getMatrix();
    m*2;
}

TEST(Matrix, TestMult2) { // OPERATOR * (matrix multiplication)
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

    Matrix<int> c = a * b;
}*/