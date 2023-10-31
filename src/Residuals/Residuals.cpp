#include "Residuals.h"

double Residuals::L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    // norm(b - A@x)
    // Takes in A, b, x to calculate L1 norm
    DenseVector sub = DVOps::elemSub(b, DVOps::DVMOps::matMul(A,x));
    return DVOps::norm(sub, 1.0);

}