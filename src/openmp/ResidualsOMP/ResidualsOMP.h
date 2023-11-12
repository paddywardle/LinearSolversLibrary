#ifndef RESIDUALSOMP_H
#define RESIDUALSOMP_H

#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../VecOpsOMP/DVOpsOMP.h"

namespace ResidualsOMP {

    DenseVector residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x);

    double L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x);

};

#endif