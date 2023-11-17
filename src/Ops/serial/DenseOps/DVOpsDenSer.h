#ifndef OPS_H
#define OPS_H

#include "../../DVOps.h"
#include "../../../Matrix/DenseMatrix.h"
#include "../../../Vector/DenseVector.h"

class DVOpsDenSer : public DVOps<>{

    public:
        Vector& scalarMult(const Vector& vecA, const double val) const;

        Vector& matVecMul(const Matrix& mat, const Vector& vec) const;

        Vector& vecMatMul(const Vector& vec, const Matrix& mat) const;

        double norm(const Vector& vecA, const double ord=2.0) const;

        double dot(const Vector& vecA, const Vector& vecB) const;

        double vecSum(const Vector& vec) const;

};

#endif