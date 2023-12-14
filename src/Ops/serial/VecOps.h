#ifndef VECOPS_H
#define VECOPS_H

#include <numeric>
#include <cmath>

#include "../Ops.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Matrix/Sparse/SparseMatrix.h"
#include "../../Vector/Sparse/SparseVector.h"

template<typename Matrix, typename Vector>
class VecOps : public Ops<Vector>{

    public:

        Vector elemMult(const Vector& matA, const Vector& matB) const override;

        Vector elemAdd(const Vector& matA, const Vector& matB) const override;

        Vector elemSub(const Vector& matA, const Vector& matB) const override;

        Vector elemDiv(const Vector& matA, const Vector& matB) const override;

        Vector scalarMult(const Vector& vecA, const double val) const override;

        Vector matVecMul(const Matrix& mat, const Vector& vec) const override;

        Vector vecMatMul(const Vector& vec, const Matrix& mat) const override;

        Vector zeros(const int len) const;

        Vector ones(const int len) const;

        double norm(const Vector& vecA, const double ord=2.0) const;

        double dot(const Vector& vecA, const Vector& vecB) const;

        double vecSum(const Vector& vec) const;

};

template<>
class VecOps<DenseMatrix, DenseVector> : public Ops<DenseVector>{

    public:
    
        static VecOps<DenseMatrix, DenseVector>& getInstance(){
            static VecOps<DenseMatrix, DenseVector> instance;
            return instance;
        }
        
        ~VecOps(){}
        
        DenseVector elemMult(const DenseVector& matA, const DenseVector& matB) const override;

        DenseVector elemAdd(const DenseVector& matA, const DenseVector& matB) const override;

        DenseVector elemSub(const DenseVector& matA, const DenseVector& matB) const override;

        DenseVector elemDiv(const DenseVector& matA, const DenseVector& matB) const override;
        
        DenseVector zeros(const int len) const;

        DenseVector ones(const int len) const;

        DenseVector scalarMult(const DenseVector& vecA, const double val) const;

        DenseVector matVecMul(const DenseMatrix& mat, const DenseVector& vec) const;

        DenseVector vecMatMul(const DenseVector& vec, const DenseMatrix& mat) const;

        double norm(const DenseVector& vecA, const double ord=2.0) const;

        double dot(const DenseVector& vecA, const DenseVector& vecB) const;

        double vecSum(const DenseVector& vec) const;

    private:
        VecOps(){}
        VecOps(const VecOps<DenseMatrix, DenseVector>&) = delete;
        VecOps<DenseMatrix, DenseVector>& operator=(const VecOps<DenseMatrix, DenseVector>&) = delete;

};

template<>
class VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>> : public Ops<SparseVector<SparseTypes::IDX>>{

    public:
    
        static VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>& getInstance(){
            static VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>> instance;
            return instance;
        }
        
        ~VecOps(){}
        
        SparseVector<SparseTypes::IDX> elemMult(const SparseVector<SparseTypes::IDX>& matA, const SparseVector<SparseTypes::IDX>& matB) const override;

        SparseVector<SparseTypes::IDX> elemAdd(const SparseVector<SparseTypes::IDX>& matA, const SparseVector<SparseTypes::IDX>& matB) const override;

        SparseVector<SparseTypes::IDX> elemSub(const SparseVector<SparseTypes::IDX>& matA, const SparseVector<SparseTypes::IDX>& matB) const override;

        SparseVector<SparseTypes::IDX> elemDiv(const SparseVector<SparseTypes::IDX>& matA, const SparseVector<SparseTypes::IDX>& matB) const override;
        
        SparseVector<SparseTypes::IDX> zeros(const int len) const;

        SparseVector<SparseTypes::IDX> ones(const int len) const;

        SparseVector<SparseTypes::IDX> scalarMult(const SparseVector<SparseTypes::IDX>& vecA, const double val) const;

        SparseVector<SparseTypes::IDX> matVecMul(const SparseMatrix<SparseTypes::IDX>& mat, const SparseVector<SparseTypes::IDX>& vec) const;

        SparseVector<SparseTypes::IDX> vecMatMul(const SparseVector<SparseTypes::IDX>& vec, const SparseMatrix<SparseTypes::IDX>& mat) const;

        double norm(const SparseVector<SparseTypes::IDX>& vecA, const double ord=2.0) const;

        double dot(const SparseVector<SparseTypes::IDX>& vecA, const SparseVector<SparseTypes::IDX>& vecB) const;

        double vecSum(const SparseVector<SparseTypes::IDX>& vec) const;

    private:
        VecOps(){}
        VecOps(const VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>&) = delete;
        VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>& operator=(const VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>&) = delete;

};

#endif