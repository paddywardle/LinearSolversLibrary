#ifndef CONJUGATEGRADIENTDENSE_H
#define CONJUGATEGRADIENTDENSE_H

#include "../LinearSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Ops/serial/DVOps.h"
#include "../../Residuals/Residuals.h"

template<Matrix, Vector>
class ConjugateGradientDense: public LinearSolver<Matrix, Vector>{

    public:

        Vector& solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        double alpha(const Matrix& A, const Vector& r, const Vector& p) const;
        
        double beta(const Vector& r, const Vector& rPlus1) const;

};

template<>
class ConjugateGradientDense<DenseMatrix, DenseVector>: public LinearSolver<DenseMatrix, DenseVector>{

    public:

        DenseVector& solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts, const double tol) const override;

        double alpha(const DenseMatrix& A, const DenseVector& r, const DenseVector& p) const;
        
        double beta(const DenseVector& r, const DenseVector& rPlus1) const;

};

#endif