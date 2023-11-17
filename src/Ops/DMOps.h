#ifndef DMOPS_H
#define DMOPS_H

#include "Ops.h"

template<typename Matrix>
class DMOps : public Ops<Matrix> {

    public:
        Matrix& matMul(const Matrix& matA, const Matrix& matB) const;

};

#endif