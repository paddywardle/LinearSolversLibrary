#ifndef DENSEMATRIX_H
#define DENSEMATRIX_H

#include <vector>
#include <iostream>

#include "Matrix.h"
#include "../Exceptions/DenseMatrixExceptions.h"

class DenseMatrix: public Matrix {

    private:
        size_t rows;
        size_t cols;
        std::vector<double>* data_;

    public:
        
        // Instantiation
        DenseMatrix(const std::vector<std::vector<double>> data_={});
        ~DenseMatrix();
        
        // Access functions
        size_t numRows() const override;
        size_t numCols() const override;
        std::vector<double> getData() const override;

        // Overloads
        double& operator()(int row, int col);
        const double& operator()(int row, int col) const;
        friend std::ostream& operator<<(std::ostream& os, const DenseMatrix& denseMat);  

};

#endif