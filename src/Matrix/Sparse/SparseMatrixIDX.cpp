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
                    data_[{i,j}] = initialData[i][j];
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

    std::vector<double> values;
    for (const auto& value: this->data_){
        values.push_back(value.second);
    }
    return values;
}

std::vector<int> SparseMatrix<SparseTypes::IDX>::getColIdx() const{

    std::vector<int> colIndices;
    for (const auto& value: this->data_){
        colIndices.push_back(value.first[1]);
    }
    return colIndices;
}

std::vector<int> SparseMatrix<SparseTypes::IDX>::getRowIdx() const{

    std::vector<int> rowIndices;
    for (const auto& value: this->data_){
        rowIndices.push_back(value.first[0]);
    }
    return rowIndices;
}

std::unordered_map<std::vector<int>,double,VectorHasher> SparseMatrix<SparseTypes::IDX>::getDataMap() const{
    return this->data_;
}

double& SparseMatrix<SparseTypes::IDX>::operator()(const int row, const int col){

    // Setting overload
    if ((row < 0) || (col < 0) || (row >= this->numRows()) || (col >= this->numCols())){
        throw DenseMatrixExceptions("Index Error: Out of bounds!");
    }

    auto it = this->data_.find({row, col});

    if (it != this->data_.end()){
        return it->second;
    }
    
    return this->data_[{row, col}];
}

const double& SparseMatrix<SparseTypes::IDX>::operator()(const int row, const int col) const{

    // Access overload
    if ((row < 0) || (col < 0) || (row >= this->numRows()) || (col >= this->numCols())){
        throw DenseMatrixExceptions("Index Error: Out of bounds!");
    }

    auto it = this->data_.find({row, col});

    if (it != this->data_.end()){
        return it->second;
    }

    return this->defaultZero;
}

SparseMatrix<SparseTypes::IDX>& SparseMatrix<SparseTypes::IDX>::operator=(const SparseMatrix<SparseTypes::IDX>& mat){

    // guard clause for if this = mat (matrix being fed in)
    // avoids unnecessary reallocation
    // CHANGE - need to put indices here!
    if (this != &mat){
        this->data_ = mat.getDataMap();
    }
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SparseMatrix<SparseTypes::IDX>& sparseMat){
    
    int matRows = sparseMat.numRows();
    int matCols = sparseMat.numCols();

    const std::vector<double>& matData = sparseMat.getData();

    for (int i=0; i<matRows; i++){
        for (int j=0; j<matCols; j++){
            os<<sparseMat(i,j)<<" ";
        }
        os<<"\n";
    }

    return os;
}