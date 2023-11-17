#ifndef STEEPESTDESCENT_H
#define STEEPESTDESCENT_H

#include "../LinearSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Ops/serial/DVOps.h"
#include "../../Residuals/Residuals.h"

template<typename Matrix,  typename Vector>
class SteepestDescent : public LinearSolver<Matrix, Vector>{

    public:

        Vector& solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        double alpha(const Matrix& A, const Vector& r) const;

};

template<>
class SteepestDescent<DenseMatrix, DenseVector>: public LinearSolver<DenseMatrix, DenseVector>{
    
    public:

        DenseVector& solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts, const double tol) const override;

        double alpha(const DenseMatrix& A, const DenseVector& r) const;

};

#endif