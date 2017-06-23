/* MATRIX
 * by Paula Mihalcea
 *
 * UniFi - Ingegneria Informatica
 * Laboratorio di programmazione
 */

#include "gtest/gtest.h"
#include "../Matrix.h"

using namespace std;

TEST(Matrix, TestDefaultConstructor) {
    Matrix<int> m(2, 3, 0); // matrix initialised to all zeros

    for (int i = 1; i <= m.getRows(); i++) {
        for (int j = 1; j <= m.getCols(); j++)
            ASSERT_EQ(0, m.getValue(i, j)); // value in the matrix; should be zero
    }

    Matrix<float> a(0, 1, 0);
    Matrix<float> b(1, 0, 0);
    Matrix<float> c(-57, 1, 0);
    Matrix<float> d(1, -96, 0);
}

TEST(Matrix, TestGetRows) {
    Matrix<int> m(10, 6, 0); // 10x6 matrix

    ASSERT_EQ(10, m.getRows());
}

TEST(Matrix, TestGetCols) {
    Matrix<int> m(10, 8, 0); // 10x6 matrix

    ASSERT_EQ(8, m.getCols());
}

TEST(Matrix, TestSetGetValue) {
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

    ASSERT_EQ(1, m.getValue(1, 1));
    ASSERT_EQ(2, m.getValue(1, 2));
    ASSERT_EQ(3, m.getValue(1, 3));
    ASSERT_EQ(5, m.getValue(2, 1));
    ASSERT_EQ(6, m.getValue(2, 2));
    ASSERT_EQ(7, m.getValue(2, 3));
    ASSERT_EQ(9, m.getValue(3, 1));
    ASSERT_EQ(10, m.getValue(3, 2));
    ASSERT_EQ(11, m.getValue(3, 3));
    ASSERT_EQ(13, m.getValue(4, 1));
    ASSERT_EQ(14, m.getValue(4, 2));
    ASSERT_EQ(15, m.getValue(4, 3));

    ASSERT_DEATH(m.setValue(1, 6, 8), "Invalid x or y.");
    ASSERT_DEATH(m.setValue(0, 1, 8), "Invalid x or y.");
    ASSERT_DEATH(m.setValue(1, 0, 8), "Invalid x or y.");
    ASSERT_DEATH(m.setValue(-36, 1, 8), "Invalid x or y.");
    ASSERT_DEATH(m.setValue(2, -52, 8), "Invalid x or y.");
    ASSERT_DEATH(m.setValue(0, 0, 8), "Invalid x or y.");

    ASSERT_DEATH(m.getValue(1, 6), "Invalid x or y.");
    ASSERT_DEATH(m.getValue(0, 1), "Invalid x or y.");
    ASSERT_DEATH(m.getValue(1, 0), "Invalid x or y.");
    ASSERT_DEATH(m.getValue(-36, 1), "Invalid x or y.");
    ASSERT_DEATH(m.getValue(2, -52), "Invalid x or y.");
    ASSERT_DEATH(m.getValue(0, 0), "Invalid x or y.");
}

TEST(Matrix, TestGetRow) {
    Matrix<float> m(3, 2, 0);

    /* MATRIX (3x2)
     *  1   2
     *  5   6
     *  9  10
    */

    m.setValue(1, 1, 1);
    m.setValue(1, 2, 2);
    m.setValue(2, 1, 5);
    m.setValue(2, 2, 6);
    m.setValue(3, 1, 9);
    m.setValue(3, 2, 10);

    Matrix<float> n = m.getRow(3);
    ASSERT_EQ(9, n.getValue(1, 1));
    ASSERT_EQ(10, n.getValue(1, 2));

    ASSERT_DEATH(n.getValue(2, 1), "Invalid x or y.");
    ASSERT_DEATH(n.getValue(0, 9), "Invalid x or y.");
    ASSERT_DEATH(n.getValue(1, 3), "Invalid x or y.");
    ASSERT_DEATH(n.getValue(1, -25), "Invalid x or y.");
}

TEST(Matrix, TestGetCol) {
    Matrix<float> m(3, 2, 0);

    /* MATRIX (3x2)
     *  1   2
     *  5   6
     *  9  10
    */

    m.setValue(1, 1, 1);
    m.setValue(1, 2, 2);
    m.setValue(2, 1, 5);
    m.setValue(2, 2, 6);
    m.setValue(3, 1, 9);
    m.setValue(3, 2, 10);

    Matrix<float> n = m.getCol(2);
    ASSERT_EQ(2, n.getValue(1, 1));
    ASSERT_EQ(6, n.getValue(2, 1));
    ASSERT_EQ(10, n.getValue(3, 1));

    ASSERT_DEATH(n.getValue(2, 0), "Invalid x or y.");
    ASSERT_DEATH(n.getValue(1, -14), "Invalid x or y.");
    ASSERT_DEATH(n.getValue(-5, 1), "Invalid x or y.");
    ASSERT_DEATH(n.getValue(0, 1), "Invalid x or y.");
}

TEST(Matrix, TestAssign) {
    Matrix<int> a(2, 2, 2);

    /* MATRIX (2x2)
     *  1   2
     *  5   6
    */

    a.setValue(1, 1, 1);
    a.setValue(1, 2, 2);
    a.setValue(2, 1, 5);
    a.setValue(2, 2, 6);

    Matrix<int> b = a;

    ASSERT_EQ(1, b.getValue(1, 1));
    ASSERT_EQ(2, b.getValue(1, 2));
    ASSERT_EQ(5, b.getValue(2, 1));
    ASSERT_EQ(6, b.getValue(2, 2));

    Matrix<int>c(1, 2, 2);

    ASSERT_DEATH(c = a, "Number of rows and cols should be the same for both matrices.");
}

TEST(Matrix, TestEqual) {
    Matrix<int> a(2, 2, 2);

    /* MATRIX (2x2)
     *  1   2
     *  5   6
    */

    a.setValue(1, 1, 1);
    a.setValue(1, 2, 2);
    a.setValue(2, 1, 5);
    a.setValue(2, 2, 6);

    Matrix<int> b = a;

    bool flag_b;

    flag_b = b == a;

    ASSERT_EQ(true, flag_b);

    Matrix<int> c(2, 2, 2);

    c.setValue(1, 1, 1);
    c.setValue(1, 2, 2);
    c.setValue(2, 1, 5);
    c.setValue(2, 2, 7);

    bool flag_c;

    flag_c = c == a;

    ASSERT_EQ(false, flag_c);
}

TEST(Matrix, TestSum) {
    Matrix<int> a(2, 2, 2);

    /* MATRIX (2x2)
     *  1   2
     *  5   6
    */

    a.setValue(1, 1, 1);
    a.setValue(1, 2, 2);
    a.setValue(2, 1, 5);
    a.setValue(2, 2, 6);

    Matrix<int> b(2, 2, 1);

    Matrix<int> c = a + b;

    /* MATRIX (2x2)
     *  2   3
     *  6   7
    */

    ASSERT_EQ(2, c.getValue(1, 1));
    ASSERT_EQ(3, c.getValue(1, 2));
    ASSERT_EQ(6, c.getValue(2, 1));
    ASSERT_EQ(7, c.getValue(2, 2));

    Matrix<int> d(3, 3, 1);

    ASSERT_DEATH(d + a, "Number of rows and cols should be the same for both matrices.");
}

TEST(Matrix, TestSub) {
    Matrix<int> a(2, 2, 2);

    /* MATRIX (2x2)
     *  1   2
     *  5   6
    */

    a.setValue(1, 1, 1);
    a.setValue(1, 2, 2);
    a.setValue(2, 1, 5);
    a.setValue(2, 2, 6);

    Matrix<int> b(2, 2, 1);

    Matrix<int> c = a - b;

    /* MATRIX (2x2)
     *  0   1
     *  4   5
    */

    ASSERT_EQ(0, c.getValue(1, 1));
    ASSERT_EQ(1, c.getValue(1, 2));
    ASSERT_EQ(4, c.getValue(2, 1));
    ASSERT_EQ(5, c.getValue(2, 2));

    Matrix<int> d(3, 3, 1);

    ASSERT_DEATH(d - a, "Number of rows and cols should be the same for both matrices.");
}

TEST(Matrix, TestMultScalar) {
    Matrix<int> m(3, 1, 3);

    /* MATRIX (3x1)
     *  0
     *  -3
     *  2
    */

    m.setValue(1, 1, 0);
    m.setValue(2, 1, -3);
    m.setValue(3, 1, 2);

    m * 2;

    /* MATRIX (3x1)
     *  0
     *  -6
     *  4
    */

    ASSERT_EQ(0, m.getValue(1, 1));
    ASSERT_EQ(-6, m.getValue(2, 1));
    ASSERT_EQ(4, m.getValue(3, 1));
}

TEST(Matrix, TestMultMatrix) {
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

    Matrix<int> d(1, 2, 1);

    ASSERT_DEATH(d * a, "Number of cols in the first matrix should be equal to the number of rows in the second matrix"
            ".");
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

    ASSERT_DEATH(t.getValue(4, 0), "Invalid x or y.");
    ASSERT_DEATH(t.getValue(4, 1), "Invalid x or y.");
    ASSERT_DEATH(t.getValue(1, -14), "Invalid x or y.");
    ASSERT_DEATH(t.getValue(1, 5), "Invalid x or y.");
    ASSERT_DEATH(t.getValue(0, 1), "Invalid x or y.");
    ASSERT_DEATH(t.getValue(1, 0), "Invalid x or y.");
}