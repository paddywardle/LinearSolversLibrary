#ifndef DVOPSMPI_H
#define DVOPSMPI_H

#include <vector>
#include <cmath>
#include <numeric>
#include <mpi.h>

#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Exceptions/DenseVectorExceptions.h"
#include "../MPIOps/MPIOps.h"

namespace DVOpsMPI {

    DenseVector elemMult(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector elemAdd(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector elemSub(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector elemDiv(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector scalarMult(const DenseVector& vecA, const double val);

    double norm(const DenseVector& vecA, const double ord=2.0);

    double dot(const DenseVector& vecA, const DenseVector& vecB);

    double vecSum(const DenseVector& vec);

    namespace DVMOps{
        
        DenseVector matVecMul(const DenseMatrix& mat, const DenseVector& vec);
        DenseVector vecMatMul(const DenseVector& vec, const DenseMatrix& mat);

    };

};

#endif