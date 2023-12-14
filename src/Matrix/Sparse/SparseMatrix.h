#ifndef SparseMatrix_H
#define SparseMatrix_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

#include "../Matrix.h"
#include "../../utils/SparseTypes.h"
#include "../../Exceptions/DenseMatrixExceptions.h"
#include "../../utils/VectorHasher.h"

template<SparseTypes sparseType>
class SparseMatrix: public Matrix {

    private:
        int defaultZero = 0;
        size_t rows;
        size_t cols;

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
        SparseMatrix<sparseType> operator*(const SparseMatrix<sparseType>& mat);
        friend std::ostream& operator<<(std::ostream& os, const SparseMatrix<sparseType>& sparseMat);

};

template<>
class SparseMatrix<SparseTypes::IDX>: public Matrix {

    private:
        double defaultZero = 0;
        size_t rows;
        size_t cols;
        std::unordered_map<std::vector<int>,double,VectorHasher> data_;

    public:
        
        // Instantiation
        SparseMatrix(const std::vector<std::vector<double>> data_={});
        ~SparseMatrix(){};
        
        // Access functions
        size_t numRows() const override;
        size_t numCols() const override;
        std::vector<double> getData() const override;
        std::vector<int> getColIdx() const;
        std::vector<int> getRowIdx() const;
        std::unordered_map<std::vector<int>,double,VectorHasher> getDataMap() const;

        // Alter functions
        void dropIdx(const std::vector<int> Idx);
        void setMat(const int& row_nums, const int& col_nums, const std::unordered_map<std::vector<int>,double,VectorHasher>& matMap);

        // Overloads
        double& operator()(const int row, const int col);
        const double& operator()(const  int row, const int col) const;
        SparseMatrix<SparseTypes::IDX>& operator=(const SparseMatrix& mat);
        SparseMatrix<SparseTypes::IDX> operator*(const SparseMatrix<SparseTypes::IDX>& mat);
        friend std::ostream& operator<<(std::ostream& os, const SparseMatrix<SparseTypes::IDX>& sparseMat);

};

#endif