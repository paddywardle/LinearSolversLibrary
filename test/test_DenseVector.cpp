#include <gtest/gtest.h>
#include <vector>

#include "../src/Vector/DenseVector.h"
#include "../src/VecOps/DVOps.h"

TEST(DenseVectorTest, numRowsCols) {

    std::vector<double> vector{1, 2, 3};

    DenseVector vec(vector);

    EXPECT_EQ(vec.getLen(), 3);
}

TEST(DenseVectorTest, Data) {

    std::vector<double> vector{1, 2, 3, 4, 5, 6};

    DenseVector vec(vector);

    EXPECT_EQ(vec.getData()[1], 2);
    EXPECT_EQ(vec.getData()[2], 3);
    EXPECT_EQ(vec.getData()[3], 4);
    EXPECT_EQ(vec.getData()[5], 6);
}

TEST(DenseVectorTest, VectorMultiplication) {

    std::vector<double> vecAData{1,2,3,4};
    std::vector<double> vecBData{9,10,11,12};

    DenseVector vecA(vecAData);
    DenseVector vecB(vecBData);

    DenseVector vec = DVOps::elemWise(vecA, vecB);

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