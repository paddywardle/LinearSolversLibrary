#ifndef MATOPS_H
#define MATOPS_H

#include <vector>

#include "../Ops.h"
#include "../../Matrix/DenseMatrix.h"

template<typename Matrix>
class MatOps : public Ops<Matrix> {

    public:

        Matrix matMul(const Matrix& matA, const Matrix& matB) const;

        Matrix elemMult(const Matrix& matA, const Matrix& matB) const override;

        Matrix elemAdd(const Matrix& matA, const Matrix& matB) const override;

        Matrix elemSub(const Matrix& matA, const Matrix& matB) const override;

        Matrix elemDiv(const Matrix& matA, const Matrix& matB) const override;

        Matrix scalarMult(const Matrix& vecA, const double val) const override;

        Matrix zeros(const int numRows, const int numCols) const;

        Matrix ones(const int numRows, const int numCols) const;

};

template<>
class MatOps<DenseMatrix> : public Ops<DenseMatrix> {

    public:

        static MatOps<DenseMatrix>& getInstance(){
            static MatOps<DenseMatrix> instance;
            return instance;
        }

        ~MatOps(){}

        DenseMatrix matMul(const DenseMatrix& matA, const DenseMatrix& matB) const;

        DenseMatrix elemMult(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix elemAdd(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix elemSub(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix elemDiv(const DenseMatrix& matA, const DenseMatrix& matB) const override;

        DenseMatrix scalarMult(const DenseMatrix& vecA, const double val) const override;

        DenseMatrix zeros(const int numRows, const int numCols) const;

        DenseMatrix ones(const int numRows, const int numCols) const;

    private:
        MatOps(){}
        MatOps(const MatOps<DenseMatrix>&) = delete;
        MatOps<DenseMatrix>& operator=(const MatOps<DenseMatrix>&) = delete;

};

#endif