#include <gtest/gtest.h>
#include <vector>

#include "../src/Matrix/DenseMatrix.h"

TEST(DenseMatrixTest, Data) {

    std::vector<std::vector<double>> matrix{{1, 2, 3}, {4, 5, 6}};

    DenseMatrix mat(2, 3, matrix);

    EXPECT_EQ(mat.getData()[0][1], 2);
    EXPECT_EQ(mat.getData()[0][2], 3);
    EXPECT_EQ(mat.getData()[1][0], 4);
    EXPECT_EQ(mat.getData()[1][2], 6);
}

TEST(DenseMatrixTest, DataEmpty) {

    DenseMatrix mat(2, 3);

    EXPECT_EQ(mat.getData()[0][1], 0);
    EXPECT_EQ(mat.getData()[0][2], 0);
    EXPECT_EQ(mat.getData()[1][0], 0);
    EXPECT_EQ(mat.getData()[1][2], 0);
}