#ifndef SparseMatrixIdx_H
#define SparseMatrixIdx_H

#include <vector>
#include <iostream>

#include "../Matrix.h"
#include "../../Exceptions/DenseMatrixExceptions.h"

class SparseMatrixIdx: public Matrix {

    private:
        size_t rows;
        size_t cols;
        std::vector<double> data_;
        std::vector<int> rowIdx;
        std::vector<int> colIdx; 

    public:
        
        // Instantiation
        SparseMatrixIdx(const std::vector<std::vector<double>> data_={});
        ~SparseMatrixIdx(){};
        
        // Access functions
        size_t numRows() const override;
        size_t numCols() const override;
        std::vector<double> getData() const override;

        // Overloads
        double& operator()(const int row, const int col);
        const double& operator()(const  int row, const int col) const;
        SparseMatrixIdx& operator=(const SparseMatrixIdx& mat);
        friend std::ostream& operator<<(std::ostream& os, const SparseMatrixIdx& denseMat);  

};

#endif