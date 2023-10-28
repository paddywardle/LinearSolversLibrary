#ifndef DVOPS_H
#define DVOPS_H

#include <vector>
#include <cmath>

#include "../Vector/DenseVector.h"
#include "../Exceptions/DenseVectorExceptions.h"

class DVOps {

    public:
        static DenseVector elemMult(const DenseVector& vecA, const DenseVector& vecB);

        static DenseVector elemAdd(const DenseVector& vecA, const DenseVector& vecB);

        static DenseVector elemSub(const DenseVector& vecA, const DenseVector& vecB);

        static DenseVector elemDiv(const DenseVector& vecA, const DenseVector& vecB);

        static DenseVector scalarMult(const DenseVector& vecA, const double val);

        static double norm(const DenseVector & vecA, const double ord=2);

        static double dot(const DenseVector& vecA, const DenseVector& vecB);

};

#endif