#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include "../FixedPointSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"

template<typename Matrix, typename Vector>
class GaussSeidel : public FixedPointSolver<Matrix, Vector>{

    public:

        Vector& solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        void forwardSweep(const Matrix& A, const Vector& b, Vector& x) const override;

        void backwardSweep(const Matrix& A, const Vector& b, Vector& x) const override;

};

template<>
class GaussSeidel<DenseMatrix, DenseVector> : public FixedPointSolver<DenseMatrix, DenseVector>{

    public:
        DenseVector& solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts, const double tol) const override;

        void forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

        void backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

};

#endif