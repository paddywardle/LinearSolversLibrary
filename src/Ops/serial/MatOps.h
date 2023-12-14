#ifndef MATOPS_H
#define MATOPS_H

#include <vector>
#include <algorithm>

#include "../Ops.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Matrix/Sparse/SparseMatrix.h"
#include "../../utils/VectorHasher.h"

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

template<>
class MatOps<SparseMatrix<SparseTypes::IDX>> : public Ops<SparseMatrix<SparseTypes::IDX>> {

    public:

        static MatOps<SparseMatrix<SparseTypes::IDX>>& getInstance(){
            static MatOps<SparseMatrix<SparseTypes::IDX>> instance;
            return instance;
        }

        ~MatOps(){}

        SparseMatrix<SparseTypes::IDX> matMul(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const;

        SparseMatrix<SparseTypes::IDX> elemMult(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const override;

        SparseMatrix<SparseTypes::IDX> elemAdd(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const override;

        SparseMatrix<SparseTypes::IDX> elemSub(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const override;

        SparseMatrix<SparseTypes::IDX> elemDiv(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const override;

        SparseMatrix<SparseTypes::IDX> scalarMult(const SparseMatrix<SparseTypes::IDX>& vecA, const double val) const override;

        SparseMatrix<SparseTypes::IDX> zeros(const int numRows, const int numCols) const;

        SparseMatrix<SparseTypes::IDX> ones(const int numRows, const int numCols) const;

    private:
        MatOps(){}
        MatOps(const MatOps<SparseMatrix<SparseTypes::IDX>>&) = delete;
        MatOps<SparseMatrix<SparseTypes::IDX>>& operator=(const MatOps<SparseMatrix<SparseTypes::IDX>>&) = delete;

};

#endif