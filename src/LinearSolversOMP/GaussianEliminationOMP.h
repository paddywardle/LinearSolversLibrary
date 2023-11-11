#ifndef GAUSSIANELIMINATIONOMP_H
#define GAUSSIANELIMINATIONOMP_H

#include <vector>
#include <omp.h>


#include "../Matrix/DenseMatrix.h"
#include "../Vector/DenseVector.h"
#include "../VecOps/DVOps.h"

namespace GaussianEliminationOMP {

    DenseVector solver(DenseMatrix& A, DenseVector& b);

    void elimination(DenseMatrix& A, DenseVector& b);

    DenseVector backsub(DenseMatrix& Aaug, DenseVector& baug);

};

#endif