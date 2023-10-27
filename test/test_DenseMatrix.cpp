#include <gtest/gtest.h>
#include <vector>

#include "../src/Matrix/DenseMatrix.h"
#include "../src/MatOps/DMOps.h"

TEST(DenseMatrixTest, Data) {

    std::vector<std::vector<double>> matrix{{1, 2, 3}, {4, 5, 6}};

    DenseMatrix mat(2, 3, matrix);

    EXPECT_EQ(mat.getData()[1], 2);
    EXPECT_EQ(mat.getData()[2], 3);
    EXPECT_EQ(mat.getData()[3], 4);
    EXPECT_EQ(mat.getData()[5], 6);
}

TEST(DenseMatrixTest, DataEmpty) {

    DenseMatrix mat(2, 3);

    EXPECT_EQ(mat.getData()[1], 0);
    EXPECT_EQ(mat.getData()[2], 0);
    EXPECT_EQ(mat.getData()[3], 0);
    EXPECT_EQ(mat.getData()[5], 0);
}

TEST(DenseMatrixTest, MatrixMultiplication) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}, {21,22,23,24}};

    DenseMatrix matA(3, 4, matAData);
    DenseMatrix matB(4, 4, matBData);
    DenseMatrix mat = DMOps::matMul(matA, matB);

    EXPECT_EQ(mat.getData()[1], 180);
    EXPECT_EQ(mat.getData()[5], 436);
    EXPECT_EQ(mat.getData()[7], 488);
    EXPECT_EQ(mat.getData()[10], 734);
}