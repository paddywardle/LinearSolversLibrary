#ifndef DMOPS_H
#define DMOPS_H

#include "../Ops.h"
#include "../../Matrix/DenseMatrix.h"

template<typename Matrix>
class DMOps : public Ops<Matrix> {

    public:

        Matrix matMul(const Matrix& matA, const Matrix& matB) const;

        Matrix elemMult(const Matrix& matA, const Matrix& matB) const override;

        Matrix elemAdd(const Matrix& matA, const Matrix& matB) const override;

        Matrix elemSub(const Matrix& matA, const Matrix& matB) const override;

        Matrix elemDiv(const Matrix& matA, const Matrix& matB) const override;

        Matrix scalarMult(const Matrix& vecA, const double val) const override;

};

template<>
class DMOps<DenseMatrix> : public Ops<DenseMatrix> {

    public:

        static DMOps<DenseMatrix>& getInstance(){
            static DMOps<DenseMatrix> instance;
            return instance;
        }

        ~DMOps(){}

        DenseMatrix matMul(const DenseMatrix& matA, const DenseMatrix& matB) const;

        DenseMatrix elemMult(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix elemAdd(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix elemSub(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix elemDiv(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix scalarMult(const DenseMatrix& vecA, const double val) const override;

    private:
        DMOps(){}
        DMOps(const DMOps<DenseMatrix>&) = delete;
        DMOps<DenseMatrix>& operator=(const DMOps<DenseMatrix>&) = delete;

};

#endif