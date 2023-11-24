#include "ResidualsOMP.h"

DenseVector ResidualsOMP<DenseMatrix, DenseVector>::residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    VecOpsOMP<DenseMatrix, DenseVector>& Ops=VecOpsOMP<DenseMatrix, DenseVector>::getInstance();

    return Ops.elemSub(b, Ops.matVecMul(A,x));

}

double ResidualsOMP<DenseMatrix, DenseVector>::L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    VecOpsOMP<DenseMatrix, DenseVector>& Ops=VecOpsOMP<DenseMatrix, DenseVector>::getInstance();
    // norm(b - A@x)
    // Takes in A, b, x to calculate L1 norm
    return Ops.norm(ResidualsOMP<DenseMatrix, DenseVector>::residual(A,b,x), 1.0);

}