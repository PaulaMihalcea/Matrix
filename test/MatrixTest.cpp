#include "gtest/gtest.h"

#include "../Matrix.h"

TEST(Matrix, DefaultConstructor) { // DEFAULT CONSTRUCTOR
    Matrix<int> m(4, 3, 0); // matrix initialised to all zeros
    cout << "Matrix: " << m << endl;

    for (int i=1; i<=m.getRows(); i++) {
        for (int j=1; j<=m.getCols(); j++)
            ASSERT_EQ(0, m.getValue(i, j)); // value in the matrix; should be zero
    }
}

TEST(Matrix, TestSetValue) { // SET VALUE
    Matrix<int> m(4, 3, 0);

    /* MATRIX (4x3)
     *  1   2   3
     *  5   6   7
     *  9  10  11
     * 13  14  15
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

    cout << "Matrix: " << endl << m << endl;
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

TEST(Matrix, TestEqual) { // OPERATOR =
    Matrix<int> a(2, 2, 2);
    Matrix<int> b(2, 2, 1);

    Matrix<int> c=a+b;

    for (int i=1; i<=a.getRows(); i++) {
        for (int j=1; j<=a.getCols(); j++)
            ASSERT_EQ(3, a.getValue(i, j));
    }
}

TEST(Matrix, TestCopy) {
    Matrix<int> a(5, 8, 7);
    Matrix<int> b=a;

    for (int i=1; i<=b.getRows(); i++) {
        for (int j=1; j<=b.getCols(); j++)
            ASSERT_EQ(7, b.getValue(i, j));
    }
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
    Matrix<int> m(4, 3, 0);

    /* MATRIX (4x3)
     *  1   2   3
     *  5   6   7
     *  9  10  11
     * 13  14  15
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

    Matrix<int> t = m.transpose();

    /* MATRIX (3x4)
     *  1   5   9  13
     *  2   6  10  14
     *  3   7  11  15
    */

    ASSERT_FALSE(t.getRow(4));
    ASSERT_TRUE(t.getCol(4));
    ASSERT_EQ(1, t.getValue(1, 1));
    ASSERT_EQ(5, t.getValue(1, 2));
    ASSERT_EQ(9, t.getValue(1, 3));
    ASSERT_EQ(13, t.getValue(1, 4));
    ASSERT_EQ(2, t.getValue(2, 1));
    ASSERT_EQ(6, t.getValue(2, 2));
    ASSERT_EQ(10, t.getValue(2, 3));
    ASSERT_EQ(14, t.getValue(2, 4));
    ASSERT_EQ(3, t.getValue(3, 1));
    ASSERT_EQ(7, t.getValue(3, 2));
    ASSERT_EQ(11, t.getValue(3, 3));
    ASSERT_EQ(15, t.getValue(3, 4));
}

TEST(Matrix, TestMult1) { // OPERATOR * (scalar multiplication)
    Matrix<int> m(2, 2, 3); // 2x2 matrix of all threes
    m * 2; // now should be all six

    ASSERT_EQ(6, m.getValue(1, 1));
    ASSERT_EQ(6, m.getValue(1, 2));
    ASSERT_EQ(6, m.getValue(2, 1));
    ASSERT_EQ(6, m.getValue(2, 2));
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

    Matrix<int> c = a * b; // c should be a 1x1 matrix
    ASSERT_EQ(50, c.getValue(1, 1));
}