#ifndef GAUSSIANELIMINATION_H
#define GAUSSIANELIMINATION_H

#include <vector>

#include "../Matrix/DenseMatrix.h"
#include "../Vector/DenseVector.h"
#include "../VecOps/DVOps.h"

namespace GaussianElimination {

    DenseVector solver(DenseMatrix& A, DenseVector& b);

    void elimination(DenseMatrix& A, DenseVector& b);

    DenseVector backsub(DenseMatrix& Aaug, DenseVector& baug);

};

#endif