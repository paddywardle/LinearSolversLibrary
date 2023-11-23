#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include <vector>

#include "../FixedPointSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Residuals/Residuals.h"

template<typename Matrix, typename Vector>
class GaussSeidel : public FixedPointSolver<Matrix, Vector>{

    public:

        Vector solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        void forwardSweep(const Matrix& A, const Vector& b, Vector& x) const override;

        void backwardSweep(const Matrix& A, const Vector& b, Vector& x) const override;

};

template<>
class GaussSeidel<DenseMatrix, DenseVector> : public FixedPointSolver<DenseMatrix, DenseVector>{

    public:

        static GaussSeidel<DenseMatrix, DenseVector>& getInstance(){
            static GaussSeidel<DenseMatrix, DenseVector> instance;
            return instance;
        }

        ~GaussSeidel(){}
        
        DenseVector solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts=200, const double tol=1e-5) const override;

        void forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

        void backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

    private:
        GaussSeidel(){}
        GaussSeidel(const GaussSeidel<DenseMatrix, DenseVector>&) = delete;
        GaussSeidel<DenseMatrix, DenseVector>& operator=(const GaussSeidel<DenseMatrix, DenseVector>&) = delete;

};

#endif