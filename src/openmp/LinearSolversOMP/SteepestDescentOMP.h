#ifndef STEEPESTDESCENTOMP_H
#define STEEPESTDESCENTOMP_H

#include <vector>

#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../VecOpsOMP/DVOpsOMP.h"
#include "../ResidualsOMP/ResidualsOMP.h"

namespace SteepestDescentOMP {

    DenseVector solver(const DenseMatrix& A, DenseVector& b, DenseVector x=DenseVector(), int maxIts=200, double tol=1e-5);

    double alpha(const DenseMatrix& A, const DenseVector& r);
    
};

#endif