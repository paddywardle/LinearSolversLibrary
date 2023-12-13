#include <gtest/gtest.h>
#include <vector>

#include "../../src/Matrix/Sparse/SparseMatrix.h"
#include "../../src/Ops/serial/MatOps.h"

MatOps<SparseMatrix<SparseTypes::IDX>>& SparseOperations=MatOps<SparseMatrix<SparseTypes::IDX>>::getInstance();

TEST(SparseIDXMatOpsTest, MatrixMultiplication) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}, {21,22,23,24}};

    SparseMatrix<SparseTypes::IDX> matA(matAData);
    SparseMatrix<SparseTypes::IDX> matB(matBData);

    SparseMatrix<SparseTypes::IDX> mat = SparseOperations.matMul(matA, matB);
    EXPECT_EQ(mat(0,1), 180);
    EXPECT_EQ(mat(1,1), 436);
    EXPECT_EQ(mat(1,3), 488);
    EXPECT_EQ(mat(2,2), 734);
}

TEST(SparseIDXMatOpsTest, ElementMult) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}};

    SparseMatrix<SparseTypes::IDX> matA(matAData);
    SparseMatrix<SparseTypes::IDX> matB(matBData);

    SparseMatrix<SparseTypes::IDX> mat = SparseOperations.elemMult(matA, matB);
    EXPECT_EQ(mat(0,0), 9);
    EXPECT_EQ(mat(1,0), 65);
    EXPECT_EQ(mat(1,3), 128);
    EXPECT_EQ(mat(2,2), 209);
}

TEST(SparseIDXMatOpsTest, ElementAdd) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}};

    SparseMatrix<SparseTypes::IDX> matA(matAData);
    SparseMatrix<SparseTypes::IDX> matB(matBData);

    SparseMatrix<SparseTypes::IDX> mat = SparseOperations.elemAdd(matA, matB);
    EXPECT_EQ(mat(0,0), 10);
    EXPECT_EQ(mat(1,0), 18);
    EXPECT_EQ(mat(1,3), 24);
    EXPECT_EQ(mat(2,2), 30);
}

TEST(SparseIDXMatOpsTest, ElementSub) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}};

    SparseMatrix<SparseTypes::IDX> matA(matAData);
    SparseMatrix<SparseTypes::IDX> matB(matBData);

    SparseMatrix<SparseTypes::IDX> mat = SparseOperations.elemSub(matA, matB);
    EXPECT_EQ(mat(0,0), -8);
    EXPECT_EQ(mat(1,0), -8);
    EXPECT_EQ(mat(1,3), -8);
    EXPECT_EQ(mat(2,2), -8);
}

TEST(SparseIDXMatOpsTest, ElementDiv) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}};

    SparseMatrix<SparseTypes::IDX> matA(matAData);
    SparseMatrix<SparseTypes::IDX> matB(matBData);

    SparseMatrix<SparseTypes::IDX> mat = SparseOperations.elemDiv(matA, matB);

    EXPECT_EQ(mat(0,1), 0.2);
    EXPECT_EQ(mat(1,3), 0.5);
}

TEST(SparseIDXMatOpsTest, ScalarMultiplication) {

    std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    SparseMatrix<SparseTypes::IDX> matA(matAData);

    SparseMatrix<SparseTypes::IDX> mat = SparseOperations.scalarMult(matA, 5);
    EXPECT_EQ(mat(0,1), 10);
    EXPECT_EQ(mat(1,1), 30);
    EXPECT_EQ(mat(1,3), 40);
    EXPECT_EQ(mat(2,2), 55);
}