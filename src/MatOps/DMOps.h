#ifndef DMOPS_H
#define DMOPS_H

#include <vector>

#include "../Matrix/DenseMatrix.h"
#include "../Exceptions/DenseMatrixExceptions.h"

namespace DMOps {

    DenseMatrix matMul(const DenseMatrix& matA, const DenseMatrix& matB);

    DenseMatrix scalarMult(const DenseMatrix& matA, const double val);

};

#endif