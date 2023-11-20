#ifndef JACOBIOMP_H
#define JACOBIOMP_H

#include <vector>
#include <omp.h>

#include "../FixedPointSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Residuals/ResidualsOMP.h"

template<typename Matrix, typename Vector>
class JacobiOMP : public FixedPointSolver<Matrix, Vector>{

    public:

        Vector solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        void forwardSweep(const Matrix& A, const Vector& b, Vector& x) const override;

        void backwardSweep(const Matrix& A, const Vector& b, Vector& x) const override;

};

template<>
class JacobiOMP<DenseMatrix, DenseVector> : public FixedPointSolver<DenseMatrix, DenseVector>{

    public:
    
        static JacobiOMP<DenseMatrix, DenseVector>& getInstance(){
            static JacobiOMP<DenseMatrix, DenseVector> instance;
            return instance;
        }

        DenseVector solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts=200, const double tol=1e-5) const override;

        void forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

        void backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;
    
    private:
        JacobiOMP(){}
        ~JacobiOMP(){}
        JacobiOMP(const JacobiOMP<DenseMatrix, DenseVector>&) = delete;
        JacobiOMP<DenseMatrix, DenseVector>& operator=(const JacobiOMP<DenseMatrix, DenseVector>&) = delete;
};

#endif