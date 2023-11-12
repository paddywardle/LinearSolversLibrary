#ifndef RESIDUALS_H
#define RESIDUALS_H

#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../VecOps/DVOps.h"

namespace Residuals {

    DenseVector residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x);

    double L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x);

};

#endif