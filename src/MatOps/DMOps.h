#ifndef DMOPS_H
#define DMOPS_H

#include <vector>

#include "../Matrix/DenseMatrix.h"
#include "../Exceptions/DenseMatrixExceptions.h"

class DMOps {

    public:
        static DenseMatrix matMul(const DenseMatrix& matA, const DenseMatrix& matB);

};

#endif