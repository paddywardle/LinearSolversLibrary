#ifndef STEEPESTDESCENTDENSE_H
#define STEEPESTDESCENTDENSE_H

#include "../../LinearSolver.h"
#include "../../../Matrix/DenseMatrix.h"
#include "../../../Vector/DenseVector.h"
#include "../../VecOps/DVOps.h"
#include "../../Residuals/Residuals.h"

class SteepestDescentDense: public LinearSolver<DenseMatrix, DenseVector>{
    
    public:

        static SteepestDescentDense& getInstance();

        DenseVector& solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts, const double tol) const override;

        double alpha(const DenseMatrix& A, const DenseVector& r) const;

    private:

        SteepestDescentDense() {};
        ~SteepestDescentDense() {};

        SteepestDescentDense(const SteepestDescentDense&) = delete;
        SteepestDescentDense& operator=(const SteepestDescentDense&) = delete;

};

#endif