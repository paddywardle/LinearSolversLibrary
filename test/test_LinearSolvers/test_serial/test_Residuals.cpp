#include <gtest/gtest.h>
#include <vector>

#include "../../../src/Matrix/DenseMatrix.h"
#include "../../../src/Vector/DenseVector.h"
#include "../../../src/Residuals/Residuals.h"

Residuals<DenseMatrix, DenseVector>& Residual=Residuals<DenseMatrix, DenseVector>::getInstance();

TEST(Residuals, L1MatMul) {

    DenseMatrix mat({{1, 2, 3}, {4, 5.5, 6}, {7, 8, 9}});
    DenseVector vec({1, 2.43, 3});
    
    double res = Residual.L1MatMul(mat, vec, vec);

    EXPECT_EQ(res, 97.235);
}