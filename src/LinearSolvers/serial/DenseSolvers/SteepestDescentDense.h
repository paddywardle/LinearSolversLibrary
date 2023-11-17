#ifndef STEEPESTDESCENTDENSE_H
#define STEEPESTDESCENTDENSE_H

#include "../../LinearSolver.h"
#include "../../../Matrix/DenseMatrix.h"
#include "../../../Vector/DenseVector.h"
#include "../../VecOps/DVOps.h"
#include "../../Residuals/Residuals.h"

class SteepestDescentDense: public LinearSolver<DenseMatrix, DenseVector>{
    
    public:

        // singleton static method
        static SteepestDescentDense& getInstance();

        DenseVector& solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts, const double tol) const override;

        double alpha(const DenseMatrix& A, const DenseVector& r) const;

    private:

        // private constructor and destructor so an instance can only be created through getInstance
        SteepestDescentDense() {};
        ~SteepestDescentDense() {};

        // deleting copy constructor and operator= so that another instance cannot be created (singleton)
        SteepestDescentDense(const SteepestDescentDense&) = delete;
        SteepestDescentDense& operator=(const SteepestDescentDense&) = delete;

};

#endif