#include "Residuals.h"

DenseVector Residuals::residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    return DVOps::elemSub(b, DVOps::DVMOps::matVecMul(A,x));

}

double Residuals::L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    // norm(b - A@x)
    // Takes in A, b, x to calculate L1 norm
    return DVOps::norm(Residuals::residual(A,b,x), 1.0);

}