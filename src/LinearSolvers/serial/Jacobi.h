#ifndef JACOBI_H
#define JACOBI_H

#include <vector>

#include "../FixedPointSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Residuals/Residuals.h"

template<typename Matrix, typename Vector>
class Jacobi : public FixedPointSolver<Matrix, Vector>{

    public:

        Vector solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        void forwardSweep(const Matrix& A, const Vector& b, Vector& x) const override;

        void backwardSweep(const Matrix& A, const Vector& b, Vector& x) const override;

};

template<>
class Jacobi<DenseMatrix, DenseVector> : public FixedPointSolver<DenseMatrix, DenseVector>{

    public:
    
        static Jacobi<DenseMatrix, DenseVector>& getInstance(){
            static Jacobi<DenseMatrix, DenseVector> instance;
            return instance;
        }
        
        ~Jacobi(){}
        
        DenseVector solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts=200, const double tol=1e-5) const override;

        void forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

        void backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;
    
    private:
        Jacobi(){}
        Jacobi(const Jacobi<DenseMatrix, DenseVector>&) = delete;
        Jacobi<DenseMatrix, DenseVector>& operator=(const Jacobi<DenseMatrix, DenseVector>&) = delete;
};

#endif