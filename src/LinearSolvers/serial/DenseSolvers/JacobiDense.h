#ifndef JACOBIDENSE_H
#define JACOBIDENSE_H

#include "../FixedPointSolver.h"
#include "../../../Matrix/DenseMatrix.h"
#include "../../../Vector/DenseVector.h"
#include "../../VecOps/DVOps.h"
#include "../../Residuals/Residuals.h"

class JacobiDense: public FixedPointSolver<DenseMatrix, DenseVector>{

    public:

        // singleton static method
        static JacobiDense& getInstance();

        DenseVector& solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts, const double tol) const override;

        void forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

        void backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

    private:

        // private constructor and destructor so an instance can only be created through getInstance
        JacobiDense() {};
        ~JacobiDense() {};

        // deleting copy constructor and operator= so that another instance cannot be created (singleton)
        JacobiDense(const JacobiDense&) = delete;
        JacobiDense& operator=(const JacobiDense&) = delete;

};

#endif