#ifndef STEEPESTDESCENTOMP_H
#define STEEPESTDESCENTOMP_H

#include <vector>
#include <omp.h>

#include "../IterativeSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Ops/omp/DVOpsOMP.h"
#include "../../Residuals/ResidualsOMP.h"

template<typename Matrix,  typename Vector>
class SteepestDescentOMP : public IterativeSolver<Matrix, Vector>{

    public:

        Vector solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        double alpha(const Matrix& A, const Vector& r) const;

};

template<>
class SteepestDescentOMP<DenseMatrix, DenseVector>: public IterativeSolver<DenseMatrix, DenseVector>{
    
    public:

        static SteepestDescentOMP<DenseMatrix, DenseVector>& getInstance(){
            static SteepestDescentOMP<DenseMatrix, DenseVector> instance;
            return instance;
        }

        DenseVector solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts=200, const double tol=1e-5) const override;

        double alpha(const DenseMatrix& A, const DenseVector& r) const;

    private:
        SteepestDescentOMP(){}
        ~SteepestDescentOMP(){}
        SteepestDescentOMP(const SteepestDescentOMP<DenseMatrix, DenseVector>&) = delete;
        SteepestDescentOMP<DenseMatrix, DenseVector>& operator=(const SteepestDescentOMP<DenseMatrix, DenseVector>&) = delete;

};

#endif