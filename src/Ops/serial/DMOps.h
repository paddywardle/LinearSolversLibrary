#ifndef DMOPS_H
#define DMOPS_H

#include "../Ops.h"
#include "../../Matrix/DenseMatrix.h"

template<typename Matrix>
class DMOps : public Ops<Matrix> {

    public:
        Matrix& matMul(const Matrix& matA, const Matrix& matB) const;

};

template<>
class DMOps<DenseMatrix> : public Ops<DenseMatrix> {

    public:
        DenseMatrix& matMul(const DenseMatrix& matA, const DenseMatrix& matB) const;

};

#endif