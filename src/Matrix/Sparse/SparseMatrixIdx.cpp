#include <iostream>

#include "SparseMatrixIdx.h"

SparseMatrixIdx::SparseMatrixIdx(const std::vector<std::vector<double>> initialData){

    rows = initialData.size();

    size_t colTmp = initialData[0].size();

    for (int i=1; i<rows; i++){
        if (initialData[i].size() != colTmp){
            throw DenseMatrixExceptions("Error: Invalid matrix structure!");
        }
    }

    cols = colTmp;
    
    if (!initialData.empty()){
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){

                data_.emplace_back();
                rowIdx.emplace_back();
                colIdx.emplace_back();

                if (initialData[i][j] == 0.0){
                    data_.push_back(initialData[i][j]);
                    rowIdx.push_back(i);
                    colIdx.push_back(j);
                }
            }
        }
    }
};

size_t SparseMatrixIdx::numRows() const{ 
    return this->rows;
}

size_t SparseMatrixIdx::numCols() const{
    return this->cols;
}

std::vector<double> SparseMatrixIdx::getData() const{
    return data_;
}

double& SparseMatrixIdx::operator()(const int row, const int col){

    // Setting overload
    if ((row < 0) || (col < 0) || (row >= this->numRows()) || (col >= this->numCols())){
        throw DenseMatrixExceptions("Index Error: Out of bounds!");
    }
    return (data_)[row*this->numCols()+col];
}

const double& SparseMatrixIdx::operator()(const int row, const int col) const{

    // Access overload
    if ((row < 0) || (col < 0) || (row >= this->numRows()) || (col >= this->numCols())){
        throw DenseMatrixExceptions("Index Error: Out of bounds!");
    }
    return (data_)[row*this->numCols()+col];
}

SparseMatrixIdx& SparseMatrixIdx::operator=(const SparseMatrixIdx& mat){

    // guard clause for if this = mat (matrix being fed in)
    // avoids unnecessary reallocation
    if (this != &mat){
        this->rows = mat.numRows();
        this->cols = mat.numCols();
        this->data_ = mat.getData();
    }
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SparseMatrixIdx& denseMat){
    
    int matRows = denseMat.numRows();
    int matCols = denseMat.numCols();

    const std::vector<double>& matData = denseMat.getData();

    for (int i=0; i<matRows; i++){
        for (int j=0; j<matCols; j++){

            os<<matData[i*matCols+j]<<" ";
        }
        os<<"\n";
    }

    return os;
}