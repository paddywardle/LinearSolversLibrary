#ifndef JACOBI_H
#define JACOBI_H

#include <vector>

#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../VecOps/DVOps.h"
#include "../Residuals/Residuals.h"

namespace Jacobi {

    DenseVector solver(const DenseMatrix& A, DenseVector& b, DenseVector x=DenseVector(), int maxIts=200, double tol=1e-5);

    void forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x);

    void backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x);

};

#endif