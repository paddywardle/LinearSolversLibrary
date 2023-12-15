#include <gtest/gtest.h>
#include <vector>

#include "../../src/Matrix/Sparse/SparseMatrix.h"
#include "../../src/Vector/Sparse/SparseVector.h"
#include "../../src/Ops/serial/VecOps.h"

VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>& OpsVecSparse=VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::getInstance();


TEST(SparseVecOpsTest, VectorMultiplication) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    SparseVector<SparseTypes::IDX> vecA(vecAData);
    SparseVector<SparseTypes::IDX> vecB(vecBData);

    SparseVector<SparseTypes::IDX> vec = OpsVecSparse.elemMult(vecA, vecB);

    EXPECT_EQ(vec(0), 9);
    EXPECT_EQ(vec(1), 20);
    EXPECT_EQ(vec(2), 33);
    EXPECT_EQ(vec(3), 48);
}

TEST(SparseVecOpsTest, DotProduct) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    SparseVector<SparseTypes::IDX> vecA(vecAData);
    SparseVector<SparseTypes::IDX> vecB(vecBData);

    double dotResult = OpsVecSparse.dot(vecA, vecB);

    EXPECT_EQ(dotResult, 110);
}

TEST(SparseVecOpsTest, VectorAddition) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    SparseVector<SparseTypes::IDX> vecA(vecAData);
    SparseVector<SparseTypes::IDX> vecB(vecBData);

    SparseVector<SparseTypes::IDX> vec = OpsVecSparse.elemAdd(vecA, vecB);

    EXPECT_EQ(vec(0), 10);
    EXPECT_EQ(vec(1), 12);
    EXPECT_EQ(vec(2), 14);
    EXPECT_EQ(vec(3), 16);
}

TEST(SparseVecOpsTest, VectorSubtraction) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    SparseVector<SparseTypes::IDX> vecA(vecAData);
    SparseVector<SparseTypes::IDX> vecB(vecBData);

    SparseVector<SparseTypes::IDX> vec = OpsVecSparse.elemSub(vecA, vecB);

    EXPECT_EQ(vec(0), -8);
    EXPECT_EQ(vec(1), -8);
    EXPECT_EQ(vec(2), -8);
    EXPECT_EQ(vec(3), -8);
}

TEST(SparseVecOpsTest, VectorDivision) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    SparseVector<SparseTypes::IDX> vecA(vecAData);
    SparseVector<SparseTypes::IDX> vecB(vecBData);

    SparseVector<SparseTypes::IDX> vec = OpsVecSparse.elemDiv(vecA, vecB);

    EXPECT_DOUBLE_EQ(vec(1), 0.2);
}

TEST(SparseVecOpsTest, ScalarMultiplication) {

    std::vector<double> vecAData{1,2,3,4};
    double val = 5;

    SparseVector<SparseTypes::IDX> vecA(vecAData);

    SparseVector<SparseTypes::IDX> vec = OpsVecSparse.scalarMult(vecA, val);

    EXPECT_EQ(vec(0), 5);
    EXPECT_EQ(vec(1), 10);
    EXPECT_EQ(vec(2), 15);
    EXPECT_EQ(vec(3), 20);
}

TEST(SparseVecOpsTest, VectorNorm) {

    std::vector<double> vecAData{-0.933333, 0.3733333};

    SparseVector<SparseTypes::IDX> vecA(vecAData);

    double normResult = OpsVecSparse.norm(vecA, 1);
    EXPECT_NEAR(normResult, 1.3066666, 1e-5);
}

TEST(SparseVecOpsTest, VectorSum) {

    std::vector<double> vecAData{1,2,3,4};

    SparseVector<SparseTypes::IDX> vecA(vecAData);

    double vecSum = OpsVecSparse.vecSum(vecA);

    EXPECT_EQ(vecSum, 10);
}

TEST(SparseVecOpsTest, DVMOpsMatMul) {

    std::vector<std::vector<double>> matData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    std::vector<double> vecData{1,2,3,4};

    SparseMatrix<SparseTypes::IDX> mat(matData);
    SparseVector<SparseTypes::IDX> vec(vecData);

    SparseVector<SparseTypes::IDX> vecResults = OpsVecSparse.matVecMul(mat, vec);

    EXPECT_EQ(vecResults(0), 30);
    EXPECT_EQ(vecResults(1), 70);
    EXPECT_EQ(vecResults(2), 110);
    EXPECT_EQ(vecResults(3), 150);
}

TEST(SparseVecOpsTest, DVMOpsVecMatMul) {

    std::vector<std::vector<double>> matData{{1, 2}, {3, 4}};
    std::vector<double> vecData{1,2};

    SparseMatrix<SparseTypes::IDX> mat(matData);
    SparseVector<SparseTypes::IDX> vec(vecData);

    SparseVector<SparseTypes::IDX> vecResults = OpsVecSparse.vecMatMul(vec, mat);

    EXPECT_EQ(vecResults(0), 7);
    EXPECT_EQ(vecResults(1), 10);
}