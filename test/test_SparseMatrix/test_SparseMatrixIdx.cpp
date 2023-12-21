#include <gtest/gtest.h>
#include <vector>

#include "../../src/Matrix/Sparse/SparseMatrix.h"

TEST(SparseMatrixTest, Indexing){

    std::vector<std::vector<double>> matrix{{9, 0, 3}, {4, 0, 0}, {1, 0, 7}};

    SparseMatrix<SparseTypes::IDX> sparseMat(matrix);


    EXPECT_EQ(sparseMat(0, 0).getVal(), 9);
    EXPECT_EQ(sparseMat(0, 1).getVal(), 0);
    EXPECT_EQ(sparseMat(0, 2).getVal(), 3);
    EXPECT_EQ(sparseMat(1, 0).getVal(), 4);
    EXPECT_EQ(sparseMat(2, 0).getVal(), 1);
    EXPECT_EQ(sparseMat(2, 2).getVal(), 7);
    EXPECT_EQ(sparseMat(1, 1).getVal(), 0);

    sparseMat(1,1) = 55;

    EXPECT_EQ(sparseMat(1, 1).getVal(), 55);

}