#include "Residuals.h"

DenseVector Residuals<DenseMatrix, DenseVector>::residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    VecOps<DenseMatrix, DenseVector>& Ops=VecOps<DenseMatrix, DenseVector>::getInstance();

    return Ops.elemSub(b, Ops.matVecMul(A,x));

}

double Residuals<DenseMatrix, DenseVector>::L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    VecOps<DenseMatrix, DenseVector>& Ops=VecOps<DenseMatrix, DenseVector>::getInstance();
    // norm(b - A@x)
    // Takes in A, b, x to calculate L1 norm
    return Ops.norm(Residuals<DenseMatrix, DenseVector>::residual(A,b,x), 1.0);

}