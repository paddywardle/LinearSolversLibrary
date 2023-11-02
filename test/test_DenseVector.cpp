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

TEST(DenseVectorTest, EqualOverloading) {

    std::cout<<"hello\n";

    // the problem is that I'm allocating a pointer which is incorrect for std::vector
    // std::vector handles memory management itself <- just do std::vector, will need to sort out
    // some of the methods in it
    DenseVector vec({1, 2, 3, 4, 5, 6});
    DenseVector vec2({555, 23, 32, 47, 855, 64, 343, 33});

    std::cout<<vec<<"\n";

    vec = vec2;

    std::cout<<vec<<"\n";

    EXPECT_EQ(vec.getData()[1], 23);
    EXPECT_EQ(vec.getData()[2], 32);
    EXPECT_EQ(vec.getData()[3], 47);
    EXPECT_EQ(vec.getData()[5], 855);
    EXPECT_EQ(vec.getLen(), 8);

}