#ifndef DVOPS_H
#define DVOPS_H

#include <vector>
#include <cmath>
#include <numeric>

#include "../Matrix/DenseMatrix.h"
#include "../Vector/DenseVector.h"
#include "../Exceptions/DenseVectorExceptions.h"

namespace DVOps {

    DenseVector elemMult(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector elemAdd(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector elemSub(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector elemDiv(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector scalarMult(const DenseVector& vecA, const double val);

    double norm(const DenseVector& vecA, const double ord=2.0);

    double dot(const DenseVector& vecA, const DenseVector& vecB);

    double vecSum(const DenseVector& vec);

    namespace DVMOps{
        
        DenseVector matMul(const DenseMatrix& mat, const DenseVector& vec);

    };

};

#endif