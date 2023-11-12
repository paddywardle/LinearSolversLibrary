#ifndef DMOPSOMP_H
#define DMOPSOMP_H

#include <vector>
#include <omp.h>

#include "../../Matrix/DenseMatrix.h"
#include "../../Exceptions/DenseMatrixExceptions.h"

namespace DMOpsOMP {

    DenseMatrix matMul(const DenseMatrix& matA, const DenseMatrix& matB);

    DenseMatrix elemMult(const DenseMatrix& matA, const DenseMatrix& matB);

    DenseMatrix elemAdd(const DenseMatrix& matA, const DenseMatrix& matB);

    DenseMatrix elemSub(const DenseMatrix& matA, const DenseMatrix& matB);

    DenseMatrix elemDiv(const DenseMatrix& matA, const DenseMatrix& matB);

    DenseMatrix scalarMult(const DenseMatrix& matA, const double val);

    DenseMatrix partialPivot(DenseMatrix& A);

    DenseMatrix fullPivot(DenseMatrix& A);

    
};

#endif