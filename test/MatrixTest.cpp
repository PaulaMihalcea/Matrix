#include "gtest/gtest.h"

#include "../Matrix.h"

TEST(Matrix, DefaultConstructor) {
    Matrix<int> m(4, 3, 0);

    ASSERT_EQ(0, m.getValue(3, 2)); // value at
}

/*
TEST(GameCharacter, TestFightingMove) {
GameCharacter c;
c.setFighting(true);
c.move(1, 1);

ASSERT_FALSE(c.isFighting());
}*/
