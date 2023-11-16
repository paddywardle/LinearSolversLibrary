#ifndef GAUSSSEIDELDENSE_H
#define GAUSSSEIDELDENSE_H

#include "../FixedPointSolver.h"
#include "../../../Matrix/DenseMatrix.h"
#include "../../../Vector/DenseVector.h"
#include "../../VecOps/DVOps.h"
#include "../../Residuals/Residuals.h"

class GaussSeidelDense: public FixedPointSolver<DenseMatrix, DenseVector>{

    public:

        DenseVector& solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts, const double tol) const override;

        void forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

        void backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

};


#endif