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