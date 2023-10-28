#ifndef DVOPS_H
#define DVOPS_H

#include <vector>
#include <cmath>

#include "../Vector/DenseVector.h"
#include "../Exceptions/DenseVectorExceptions.h"

namespace DVOps {

    DenseVector elemMult(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector elemAdd(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector elemSub(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector elemDiv(const DenseVector& vecA, const DenseVector& vecB);

    DenseVector scalarMult(const DenseVector& vecA, const double val);

    double norm(const DenseVector & vecA, const double ord=2);

    double dot(const DenseVector& vecA, const DenseVector& vecB);

};

#endif