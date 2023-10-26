#ifndef DENSEMATRIX_H
#define DENSEMATRIX_H

#include <vector>

#include "Matrix.h"

class DenseMatrix: public Matrix {

    private:
        size_t rows;
        size_t cols;
        std::vector<double> data_;

    public:

        DenseMatrix(size_t numRows, size_t numCols, const std::vector<std::vector<double>> data_={});
        ~DenseMatrix(){};
        
        size_t numRows() const override;
        size_t numCols() const override;
        std::vector<double> getData() const override;

        DenseMatrix matMul(DenseMatrix& other) const;

};

#endif