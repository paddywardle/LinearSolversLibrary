#include <gtest/gtest.h>
#include <vector>

#include "../src/Vector/DenseVector.h"
#include "../src/VecOps/DVOps.h"

TEST(DenseVectorTest, VectorMultiplication) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    DenseVector vec = DVOps::elemMult(vecA, vecB);

    EXPECT_EQ(vec.getData()[0], 9);
    EXPECT_EQ(vec.getData()[1], 20);
    EXPECT_EQ(vec.getData()[2], 33);
    EXPECT_EQ(vec.getData()[3], 48);
}

TEST(DenseVectorTest, DotProduct) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    double dotResult = DVOps::dot(vecA, vecB);

    EXPECT_EQ(dotResult, 110);
}

TEST(DenseVectorTest, VectorAddition) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    DenseVector vec = DVOps::elemAdd(vecA, vecB);

    EXPECT_EQ(vec.getData()[0], 10);
    EXPECT_EQ(vec.getData()[1], 12);
    EXPECT_EQ(vec.getData()[2], 14);
    EXPECT_EQ(vec.getData()[3], 16);
}

TEST(DenseVectorTest, VectorSubtraction) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    DenseVector vec = DVOps::elemSub(vecA, vecB);

    EXPECT_EQ(vec.getData()[0], -8);
    EXPECT_EQ(vec.getData()[1], -8);
    EXPECT_EQ(vec.getData()[2], -8);
    EXPECT_EQ(vec.getData()[3], -8);
}

TEST(DenseVectorTest, VectorDivision) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    DenseVector vec = DVOps::elemDiv(vecA, vecB);

    EXPECT_DOUBLE_EQ(vec.getData()[1], 0.2);
}

TEST(DenseVectorTest, ScalarMultiplication) {

    std::vector<double> vecAData{1,2,3,4};
    double val = 5;

    DenseVector vecA(vecAData);

    DenseVector vec = DVOps::scalarMult(vecA, val);

    EXPECT_EQ(vec.getData()[0], 5);
    EXPECT_EQ(vec.getData()[1], 10);
    EXPECT_EQ(vec.getData()[2], 15);
    EXPECT_EQ(vec.getData()[3], 20);
}

TEST(DenseVectorTest, VectorNorm) {

    std::vector<double> vecAData{1,2,3,4};

    DenseVector vecA(vecAData);

    double normResult = DVOps::norm(vecA);

    EXPECT_NEAR(normResult, 5.477225575051661, 1e-5);
}