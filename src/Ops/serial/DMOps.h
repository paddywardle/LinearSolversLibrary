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

        static DMOps<DenseMatrix>& getInstance(){
            static DMOps<DenseMatrix> instance;
            return instance;
        }

        DenseMatrix& matMul(const DenseMatrix& matA, const DenseMatrix& matB) const;

    private:
        DMOps(){}
        ~DMOps(){}
        DMOps(const DMOps<DenseMatrix>&) = delete;
        DMOps<DenseMatrix>& operator=(const DMOps<DenseMatrix>&) = delete;

};

#endif