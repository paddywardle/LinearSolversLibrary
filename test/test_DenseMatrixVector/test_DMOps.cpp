#include <gtest/gtest.h>
#include <vector>

#include "../../src/Matrix/DenseMatrix.h"
#include "../../src/MatOps/DMOps.h"

TEST(DMOpsTest, MatrixMultiplication) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}, {21,22,23,24}};

    DenseMatrix matA(matAData);
    DenseMatrix matB(matBData);

    DenseMatrix mat = DMOps::matMul(matA, matB);
    EXPECT_EQ(mat.getData()[1], 180);
    EXPECT_EQ(mat.getData()[5], 436);
    EXPECT_EQ(mat.getData()[7], 488);
    EXPECT_EQ(mat.getData()[10], 734);
}

TEST(DMOpsTest, ElementMult) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}};

    DenseMatrix matA(matAData);
    DenseMatrix matB(matBData);

    DenseMatrix mat = DMOps::elemMult(matA, matB);
    EXPECT_EQ(mat.getData()[0], 9);
    EXPECT_EQ(mat.getData()[4], 65);
    EXPECT_EQ(mat.getData()[7], 128);
    EXPECT_EQ(mat.getData()[10], 209);
}

TEST(DMOpsTest, ElementAdd) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}};

    DenseMatrix matA(matAData);
    DenseMatrix matB(matBData);

    DenseMatrix mat = DMOps::elemAdd(matA, matB);
    EXPECT_EQ(mat.getData()[0], 10);
    EXPECT_EQ(mat.getData()[4], 18);
    EXPECT_EQ(mat.getData()[7], 24);
    EXPECT_EQ(mat.getData()[10], 30);
}

TEST(DMOpsTest, ElementSub) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}};

    DenseMatrix matA(matAData);
    DenseMatrix matB(matBData);

    DenseMatrix mat = DMOps::elemSub(matA, matB);
    EXPECT_EQ(mat.getData()[0], -8);
    EXPECT_EQ(mat.getData()[4], -8);
    EXPECT_EQ(mat.getData()[7], -8);
    EXPECT_EQ(mat.getData()[10], -8);
}

TEST(DMOpsTest, ElementDiv) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}};

    DenseMatrix matA(matAData);
    DenseMatrix matB(matBData);

    DenseMatrix mat = DMOps::elemDiv(matA, matB);

    EXPECT_EQ(mat.getData()[1], 0.2);
    EXPECT_EQ(mat.getData()[7], 0.5);
}

TEST(DMOpsTest, ScalarMultiplication) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    DenseMatrix matA(matAData);

    DenseMatrix mat = DMOps::scalarMult(matA, 5);
    EXPECT_EQ(mat.getData()[1], 10);
    EXPECT_EQ(mat.getData()[5], 30);
    EXPECT_EQ(mat.getData()[7], 40);
    EXPECT_EQ(mat.getData()[10], 55);
}