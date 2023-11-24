#ifndef VECOPSOMP_H
#define VECOPSOMP_H

#include <numeric>
#include <cmath>
#include <omp.h>

#include "../Ops.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"

template<typename Matrix, typename Vector>
class VecOpsOMP : public Ops<Vector>{

    public:

        Vector elemMult(const Vector& matA, const Vector& matB) const override;

        Vector elemAdd(const Vector& matA, const Vector& matB) const override;

        Vector elemSub(const Vector& matA, const Vector& matB) const override;

        Vector elemDiv(const Vector& matA, const Vector& matB) const override;

        Vector scalarMult(const Vector& vecA, const double val) const override;

        Vector matVecMul(const Matrix& mat, const Vector& vec) const override;

        Vector vecMatMul(const Vector& vec, const Matrix& mat) const override;

        double norm(const Vector& vecA, const double ord=2.0) const override;

        double dot(const Vector& vecA, const Vector& vecB) const override;

        double vecSum(const Vector& vec) const override;;

};

template<>
class VecOpsOMP<DenseMatrix, DenseVector> : public Ops<DenseVector>{

    public:
    
        static VecOpsOMP<DenseMatrix, DenseVector>& getInstance(){
            static VecOpsOMP<DenseMatrix, DenseVector> instance;
            return instance;
        }
        
        DenseVector elemMult(const DenseVector& matA, const DenseVector& matB) const override;

        DenseVector elemAdd(const DenseVector& matA, const DenseVector& matB) const override;

        DenseVector elemSub(const DenseVector& matA, const DenseVector& matB) const override;

        DenseVector elemDiv(const DenseVector& matA, const DenseVector& matB) const override;

        DenseVector scalarMult(const DenseVector& vecA, const double val) const;

        DenseVector matVecMul(const DenseMatrix& mat, const DenseVector& vec) const;

        DenseVector vecMatMul(const DenseVector& vec, const DenseMatrix& mat) const;

        double norm(const DenseVector& vecA, const double ord=2.0) const;

        double dot(const DenseVector& vecA, const DenseVector& vecB) const;

        double vecSum(const DenseVector& vec) const;

    private:
        VecOpsOMP(){}
        ~VecOpsOMP(){}
        VecOpsOMP(const VecOpsOMP<DenseMatrix, DenseVector>&) = delete;
        VecOpsOMP<DenseMatrix, DenseVector>& operator=(const VecOpsOMP<DenseMatrix, DenseVector>&) = delete;

};

#endif