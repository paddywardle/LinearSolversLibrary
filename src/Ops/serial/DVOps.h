#ifndef DVOPS_H
#define DVOPS_H

#include "../Ops.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"

template<typename Matrix, typename Vector>
class DVOps : public Ops<Vector>{

    public:
        Vector& scalarMult(const Vector& vecA, const double val) const;

        Vector& matVecMul(const Matrix& mat, const Vector& vec) const;

        Vector& vecMatMul(const Vector& vec, const Matrix& mat) const;

        double norm(const Vector& vecA, const double ord=2.0) const;

        double dot(const Vector& vecA, const Vector& vecB) const;

        double vecSum(const Vector& vec) const;

};


template<>
class DVOps<DenseMatrix, DenseVector> : public Ops<DenseMatrix>{

    public:
        DenseVector& scalarMult(const DenseVector& vecA, const double val) const;

        DenseVector& matVecMul(const DenseMatrix& mat, const DenseVector& vec) const;

        DenseVector& vecMatMul(const DenseVector& vec, const DenseMatrix& mat) const;

        double norm(const DenseVector& vecA, const double ord=2.0) const;

        double dot(const DenseVector& vecA, const DenseVector& vecB) const;

        double vecSum(const DenseVector& vec) const;

};

#endif