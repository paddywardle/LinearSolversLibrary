#ifndef CONJUGATEGRADIENTDENSE_H
#define CONJUGATEGRADIENTDENSE_H

#include "../LinearSolver.h"
#include "../../../Matrix/DenseMatrix.h"
#include "../../../Vector/DenseVector.h"
#include "../../VecOps/DVOps.h"
#include "../../Residuals/Residuals.h"

class ConjugateGradientDense: public LinearSolver<DenseMatrix, DenseVector>{

    public:

        DenseVector& solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts, const double tol) const override;

        double alpha(const DenseMatrix& A, const DenseVector& r, const DenseVector& p) const;
        
        double beta(const DenseVector& r, const DenseVector& rPlus1) const;
};

#endif