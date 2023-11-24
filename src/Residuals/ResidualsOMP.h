#ifndef RESIDUALSOMP_H
#define RESIDUALSOMP_H

#include "../Matrix/DenseMatrix.h"
#include "../Vector/DenseVector.h"
#include "../Ops/omp/VecOpsOMP.h"

template<typename Matrix, typename Vector>
class ResidualsOMP {

    public:
        
        Vector residual(const Matrix& A, const Vector& b, const Vector& x);

        double L1MatMul(const Matrix& A, const Vector& b, const Vector& x);

};

template<>
class ResidualsOMP<DenseMatrix, DenseVector> {

    public: 

        static ResidualsOMP<DenseMatrix, DenseVector>& getInstance(){
            static ResidualsOMP<DenseMatrix, DenseVector> instance;
            return instance;
        }

        DenseVector residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x);

        double L1MatMul(const DenseMatrix& A, const DenseVector& b, const DenseVector& x);
    
    private:
        ResidualsOMP(){}
        ~ResidualsOMP(){}
        ResidualsOMP(const ResidualsOMP<DenseMatrix, DenseVector>&) = delete;
        ResidualsOMP<DenseMatrix, DenseVector>& operator=(const ResidualsOMP<DenseMatrix, DenseVector>&) = delete;
};

#endif