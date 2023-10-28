#ifndef DVOPS_H
#define DVOPS_H

#include <vector>

#include "../Vector/DenseVector.h"
#include "../Exceptions/DenseVectorExceptions.h"

class DVOps {

    public:
        static DenseVector elemWise(const DenseVector& vecA, const DenseVector& vecB);

        static double dot(const DenseVector& vecA, const DenseVector& vecB);

};

#endif