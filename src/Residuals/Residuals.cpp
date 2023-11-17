#include "Residuals.h"

DenseVector Residuals<DenseMatrix, DenseVector>::residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    return DVOps<DenseMatrix, DenseVector>::elemSub(b, DVOps<DenseMatrix, DenseVector>::DVMOps::matVecMul(A,x));

}

double Residuals<DenseMatrix, DenseVector>::L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    // norm(b - A@x)
    // Takes in A, b, x to calculate L1 norm
    return DVOps<DenseMatrix, DenseVector>::norm(Residuals<DenseMatrix, DenseVector>::residual(A,b,x), 1.0);

}