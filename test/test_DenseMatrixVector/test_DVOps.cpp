#include <gtest/gtest.h>
#include <vector>

#include "../../src/Matrix/DenseMatrix.h"
#include "../../src/Vector/DenseVector.h"
#include "../../src/Ops/serial/VecOps.h"

VecOps<DenseMatrix, DenseVector>& OpsVec=VecOps<DenseMatrix, DenseVector>::getInstance();


TEST(VecOpsTest, VectorMultiplication) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    DenseVector vec = OpsVec.elemMult(vecA, vecB);

    EXPECT_EQ(vec.getData()[0], 9);
    EXPECT_EQ(vec.getData()[1], 20);
    EXPECT_EQ(vec.getData()[2], 33);
    EXPECT_EQ(vec.getData()[3], 48);
}

TEST(VecOpsTest, DotProduct) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    double dotResult = OpsVec.dot(vecA, vecB);

    EXPECT_EQ(dotResult, 110);
}

TEST(VecOpsTest, VectorAddition) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    DenseVector vec = OpsVec.elemAdd(vecA, vecB);

    EXPECT_EQ(vec.getData()[0], 10);
    EXPECT_EQ(vec.getData()[1], 12);
    EXPECT_EQ(vec.getData()[2], 14);
    EXPECT_EQ(vec.getData()[3], 16);
}

TEST(VecOpsTest, VectorSubtraction) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    DenseVector vec = OpsVec.elemSub(vecA, vecB);

    EXPECT_EQ(vec.getData()[0], -8);
    EXPECT_EQ(vec.getData()[1], -8);
    EXPECT_EQ(vec.getData()[2], -8);
    EXPECT_EQ(vec.getData()[3], -8);
}

TEST(VecOpsTest, VectorDivision) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    DenseVector vec = OpsVec.elemDiv(vecA, vecB);

    EXPECT_DOUBLE_EQ(vec.getData()[1], 0.2);
}

TEST(VecOpsTest, ScalarMultiplication) {

    std::vector<double> vecAData{1,2,3,4};
    double val = 5;

    DenseVector vecA(vecAData);

    DenseVector vec = OpsVec.scalarMult(vecA, val);

    EXPECT_EQ(vec.getData()[0], 5);
    EXPECT_EQ(vec.getData()[1], 10);
    EXPECT_EQ(vec.getData()[2], 15);
    EXPECT_EQ(vec.getData()[3], 20);
}

TEST(VecOpsTest, VectorNorm) {

    std::vector<double> vecAData{-0.933333, 0.3733333};

    DenseVector vecA(vecAData);

    double normResult = OpsVec.norm(vecA, 1);
    EXPECT_NEAR(normResult, 1.3066666, 1e-5);
}

TEST(VecOpsTest, VectorSum) {

    std::vector<double> vecAData{1,2,3,4};

    DenseVector vecA(vecAData);

    double vecSum = OpsVec.vecSum(vecA);

    EXPECT_EQ(vecSum, 10);
}

TEST(VecOpsTest, DVMOpsMatMul) {

    std::vector<std::vector<double>> matData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    std::vector<double> vecData{1,2,3,4};

    DenseMatrix mat(matData);
    DenseVector vec(vecData);

    DenseVector vecResults = OpsVec.matVecMul(mat, vec);

    EXPECT_EQ(vecResults.getData()[0], 30);
    EXPECT_EQ(vecResults.getData()[1], 70);
    EXPECT_EQ(vecResults.getData()[2], 110);
    EXPECT_EQ(vecResults.getData()[3], 150);
}

TEST(VecOpsTest, DVMOpsVecMatMul) {

    std::vector<std::vector<double>> matData{{1, 2}, {3, 4}};
    std::vector<double> vecData{1,2};

    DenseMatrix mat(matData);
    DenseVector vec(vecData);

    DenseVector vecResults = OpsVec.vecMatMul(vec, mat);

    EXPECT_EQ(vecResults.getData()[0], 7);
    EXPECT_EQ(vecResults.getData()[1], 10);
}