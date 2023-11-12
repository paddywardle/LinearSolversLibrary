#include "ResidualsOMP.h"

DenseVector ResidualsOMP::residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    return DVOpsOMP::elemSub(b, DVOpsOMP::DVMOps::matVecMul(A,x));

}

double ResidualsOMP::L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    // norm(b - A@x)
    // Takes in A, b, x to calculate L1 norm
    return DVOpsOMP::norm(ResidualsOMP::residual(A,b,x), 1.0);

}