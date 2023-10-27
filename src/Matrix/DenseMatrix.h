#ifndef DENSEMATRIX_H
#define DENSEMATRIX_H

#include <vector>
#include <iostream>

#include "Matrix.h"

class DenseMatrix: public Matrix {

    private:
        size_t rows;
        size_t cols;
        std::vector<double> data_;

    public:
        
        // Instantiation
        DenseMatrix(const size_t numRows, const size_t numCols, const std::vector<std::vector<double>> data_={});
        ~DenseMatrix(){};
        
        // Access functions
        size_t numRows() const override;
        size_t numCols() const override;
        std::vector<double> getData() const override;

        // Methods
        DenseMatrix matMul(const DenseMatrix& other) const;

        // Overloads
        friend std::ostream& operator<<(std::ostream& os, const DenseMatrix& denseMat);  

};

#endif