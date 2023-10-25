#ifndef DENSEMATRIX_H
#define DENSEMATRIX_H

#include <vector>

#include "Matrix.h"

class DenseMatrix: public Matrix {

    private:

        std::vector<std::vector<double>> data_;

    public:

        DenseMatrix(size_t numRows, size_t numCols, const std::vector<std::vector<double>> data_={});
        
        std::vector<std::vector<double>> getData() const;

};

#endif