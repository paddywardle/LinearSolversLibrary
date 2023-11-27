#ifndef SparseMatrix_H
#define SparseMatrix_H

#include <vector>
#include <algorithm>
#include <iostream>

#include "../Matrix.h"
#include "SparseTypes.h"
#include "../../Exceptions/DenseMatrixExceptions.h"

template<SparseTypes sparseType>
class SparseMatrix: public Matrix {

    private:
        int defaultZero = 0;
        size_t rows;
        size_t cols;
        std::vector<double> data_;
        std::vector<int> rowIdx;
        std::vector<int> colIdx; 

    public:
        
        // Instantiation
        SparseMatrix(const std::vector<std::vector<double>> data_={});
        ~SparseMatrix(){};
        
        // Access functions
        size_t numRows() const override;
        size_t numCols() const override;
        std::vector<double> getData() const override;

        // Overloads
        double& operator()(const int row, const int col);
        const double& operator()(const  int row, const int col) const;
        SparseMatrix<sparseType>& operator=(const SparseMatrix<sparseType>& mat);
        friend std::ostream& operator<<(std::ostream& os, const SparseMatrix<sparseType>& sparseMat);

};

template<>
class SparseMatrix<SparseTypes::IDX>: public Matrix {

    private:
        double defaultZero = 0;
        size_t rows;
        size_t cols;
        std::vector<double> data_;
        std::vector<int> rowIdx;
        std::vector<int> colIdx; 

    public:
        
        // Instantiation
        SparseMatrix(const std::vector<std::vector<double>> data_={});
        ~SparseMatrix(){};
        
        // Access functions
        size_t numRows() const override;
        size_t numCols() const override;
        std::vector<double> getData() const override;

        // Overloads
        double& operator()(const int row, const int col);
        const double& operator()(const  int row, const int col) const;
        SparseMatrix<SparseTypes::IDX>& operator=(const SparseMatrix& mat);

        friend std::ostream& operator<<(std::ostream& os, const SparseMatrix<SparseTypes::IDX>& sparseMat);

};

#endif