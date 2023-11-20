#include "ResidualsOMP.h"

DenseVector ResidualsOMP<DenseMatrix, DenseVector>::residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    DVOpsOMP<DenseMatrix, DenseVector>& VecOps=DVOpsOMP<DenseMatrix, DenseVector>::getInstance();

    return VecOps.elemSub(b, VecOps.matVecMul(A,x));

}

double ResidualsOMP<DenseMatrix, DenseVector>::L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    DVOpsOMP<DenseMatrix, DenseVector>& VecOps=DVOpsOMP<DenseMatrix, DenseVector>::getInstance();
    // norm(b - A@x)
    // Takes in A, b, x to calculate L1 norm
    return VecOps.norm(ResidualsOMP<DenseMatrix, DenseVector>::residual(A,b,x), 1.0);

}