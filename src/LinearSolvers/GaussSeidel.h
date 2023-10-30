#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include <vector>

#include "../Matrix/DenseMatrix.h"
#include "../Vector/DenseVector.h"
#include "../VecOps/DVOps.h"

namespace GaussSeidel {

    DenseVector solver(const DenseMatrix& A, DenseVector& b, int maxIts=200, double tol=1e-5);

    double residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x);

    void forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x);

    void backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x);

}

#endif