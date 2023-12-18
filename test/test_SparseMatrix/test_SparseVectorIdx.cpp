#include <gtest/gtest.h>
#include <vector>

#include "../../src/Vector/Sparse/SparseVector.h"

TEST(SparseVectorTest, Indexing){

    std::vector<double> vector({9,0,0,0,0,0,0,0,5,5,3,2,4,20});

    SparseVector<SparseTypes::IDX> sparseVec(vector);

    EXPECT_EQ(sparseVec.getLen(),14);
    EXPECT_EQ(sparseVec(0).getVal(),9);
    EXPECT_EQ(sparseVec(1).getVal(),0);
    EXPECT_EQ(sparseVec(2).getVal(),0);
    EXPECT_EQ(sparseVec(3).getVal(),0);
    EXPECT_EQ(sparseVec(8).getVal(),5);
    EXPECT_EQ(sparseVec(13).getVal(),20);

    sparseVec(1) = 55;

    EXPECT_EQ(sparseVec(1).getVal(),55);

}