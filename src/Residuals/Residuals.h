#ifndef RESIDUALS_H
#define RESIDUALS_H

#include "../Matrix/DenseMatrix.h"
#include "../Vector/DenseVector.h"
#include "../Ops/serial/VecOps.h"

template<typename Matrix, typename Vector>
class Residuals {

    public:
        
        Vector residual(const Matrix& A, const Vector& b, const Vector& x);

        double L1MatMul(const Matrix& A, const Vector& b, const Vector& x);

};

template<>
class Residuals<DenseMatrix, DenseVector> {

    public: 

        static Residuals<DenseMatrix, DenseVector>& getInstance(){
            static Residuals<DenseMatrix, DenseVector> instance;
            return instance;
        }

        ~Residuals(){}

        DenseVector residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x);

        double L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x);
    
    private:
        Residuals(){}
        Residuals(const Residuals<DenseMatrix, DenseVector>&) = delete;
        Residuals<DenseMatrix, DenseVector>& operator=(const Residuals<DenseMatrix, DenseVector>&) = delete;
};

#endif