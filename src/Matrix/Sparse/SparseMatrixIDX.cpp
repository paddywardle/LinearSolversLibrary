#include <iostream>

#include "SparseMatrix.h"

SparseMatrix<SparseTypes::IDX>::SparseMatrix(const std::vector<std::vector<double>> initialData){

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

                if (initialData[i][j] != 0.0){
                    data_.emplace_back(initialData[i][j]);
                    rowIdx.emplace_back(i);
                    colIdx.emplace_back(j);
                }
            }
        }
    }
};

size_t SparseMatrix<SparseTypes::IDX>::numRows() const{ 
    return this->rows;
}

size_t SparseMatrix<SparseTypes::IDX>::numCols() const{
    return this->cols;
}

std::vector<double> SparseMatrix<SparseTypes::IDX>::getData() const{
    return this->data_;
}

std::vector<int> SparseMatrix<SparseTypes::IDX>::getColIdx() const{
    return this->colIdx;
}

std::vector<int> SparseMatrix<SparseTypes::IDX>::getRowIdx() const{
    return this->rowIdx;
}

double& SparseMatrix<SparseTypes::IDX>::operator()(const int row, const int col){

    // Setting overload
    if ((row < 0) || (col < 0) || (row >= this->numRows()) || (col >= this->numCols())){
        throw DenseMatrixExceptions("Index Error: Out of bounds!");
    }

    for (int i=0; i<this->data_.size(); i++){
        if (rowIdx[i] == row && colIdx[i] == col){
            return data_[i];
        }
    }
    
    rowIdx.push_back(row);
    colIdx.push_back(col);
    data_.push_back(this->defaultZero);

    return data_.back();
}

const double& SparseMatrix<SparseTypes::IDX>::operator()(const int row, const int col) const{

    // Access overload
    if ((row < 0) || (col < 0) || (row >= this->numRows()) || (col >= this->numCols())){
        throw DenseMatrixExceptions("Index Error: Out of bounds!");
    }

    for (int i=0; i<this->data_.size(); i++){
        if (rowIdx[i] == row && colIdx[i] == col){
            return data_[i];
        }
    }
    return this->defaultZero;
}

SparseMatrix<SparseTypes::IDX>& SparseMatrix<SparseTypes::IDX>::operator=(const SparseMatrix<SparseTypes::IDX>& mat){

    // guard clause for if this = mat (matrix being fed in)
    // avoids unnecessary reallocation
    // CHANGE - need to put indices here!
    if (this != &mat){
        this->rows = mat.numRows();
        this->cols = mat.numCols();
        this->data_ = mat.getData();
    }
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SparseMatrix<SparseTypes::IDX>& denseMat){
    
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