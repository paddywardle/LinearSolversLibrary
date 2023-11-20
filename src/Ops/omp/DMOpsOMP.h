#ifndef DMOPSOMP_H
#define DMOPSOMP_H

#include <omp.h>

#include "../Ops.h"
#include "../../Matrix/DenseMatrix.h"

template<typename Matrix>
class DMOpsOMP : public Ops<Matrix> {

    public:
        Matrix matMul(const Matrix& matA, const Matrix& matB) const;

        Matrix elemMult(const Matrix& matA, const Matrix& matB) const override;

        Matrix elemAdd(const Matrix& matA, const Matrix& matB) const override;

        Matrix elemSub(const Matrix& matA, const Matrix& matB) const override;

        Matrix elemDiv(const Matrix& matA, const Matrix& matB) const override;

        Matrix scalarMult(const Matrix& vecA, const double val) const override;

};

template<>
class DMOpsOMP<DenseMatrix> : public Ops<DenseMatrix> {

    public:

        static DMOpsOMP<DenseMatrix>& getInstance(){
            static DMOpsOMP<DenseMatrix> instance;
            return instance;
        }

        DenseMatrix matMul(const DenseMatrix& matA, const DenseMatrix& matB) const;

        DenseMatrix elemMult(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix elemAdd(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix elemSub(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix elemDiv(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix scalarMult(const DenseMatrix& vecA, const double val) const override;

    private:
        DMOpsOMP(){}
        ~DMOpsOMP(){}
        DMOpsOMP(const DMOpsOMP<DenseMatrix>&) = delete;
        DMOpsOMP<DenseMatrix>& operator=(const DMOpsOMP<DenseMatrix>&) = delete;

};

#endif