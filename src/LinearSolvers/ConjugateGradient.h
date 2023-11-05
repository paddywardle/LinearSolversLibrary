#ifndef CONJUGATEGRADIENT_H
#define CONJUGATEGRADIENT_H

#include <vector>

#include "../Matrix/DenseMatrix.h"
#include "../Vector/DenseVector.h"
#include "../VecOps/DVOps.h"
#include "../Residuals/Residuals.h"

namespace ConjugateGradient {

    DenseVector solver(const DenseMatrix& A, DenseVector& b, DenseVector x=DenseVector(), int maxIts=200, double tol=1e-5);

    double alpha(const DenseMatrix& A, const DenseVector& r, const DenseVector& p);

    double beta(const DenseVector& r, const DenseVector& rPlus1);

};

#endif