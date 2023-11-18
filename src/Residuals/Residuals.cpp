#include "Residuals.h"

DenseVector Residuals<DenseMatrix, DenseVector>::residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    DVOps<DenseMatrix, DenseVector>& VecOps=DVOps<DenseMatrix, DenseVector>::getInstance();

    return VecOps.elemSub(b, VecOps.matVecMul(A,x));

}

double Residuals<DenseMatrix, DenseVector>::L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    DVOps<DenseMatrix, DenseVector>& VecOps=DVOps<DenseMatrix, DenseVector>::getInstance();
    // norm(b - A@x)
    // Takes in A, b, x to calculate L1 norm
    return VecOps.norm(Residuals<DenseMatrix, DenseVector>::residual(A,b,x), 1.0);

}