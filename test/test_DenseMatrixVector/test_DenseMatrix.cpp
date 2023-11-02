#include <gtest/gtest.h>
#include <vector>

#include "../../src/Matrix/DenseMatrix.h"

TEST(DenseMatrixTest, numRowsCols) {

    std::vector<std::vector<double>> matrix{{1, 2, 3}, {4, 5, 6}};

    DenseMatrix mat(matrix);

    EXPECT_EQ(mat.numRows(), 2);
    EXPECT_EQ(mat.numCols(), 3);
}

TEST(DenseMatrixTest, Data) {

    std::vector<std::vector<double>> matrix{{1, 2, 3}, {4, 5, 6}};

    DenseMatrix mat(matrix);

    EXPECT_EQ(mat.getData()[1], 2);
    EXPECT_EQ(mat.getData()[2], 3);
    EXPECT_EQ(mat.getData()[3], 4);
    EXPECT_EQ(mat.getData()[5], 6);
}