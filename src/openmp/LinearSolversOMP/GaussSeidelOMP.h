#ifndef GAUSSSEIDELOMP_H
#define GAUSSSEIDELOMP_H

#include <vector>
#include <omp.h>

#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../VecOpsOMP/DVOpsOMP.h"
#include "../ResidualsOMP/ResidualsOMP.h"

namespace GaussSeidelOMP {

    DenseVector solver(const DenseMatrix& A, DenseVector& b, DenseVector x=DenseVector(), int maxIts=200, double tol=1e-5);

    void forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x);

    void backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x);

};

#endif