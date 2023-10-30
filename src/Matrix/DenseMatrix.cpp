#include <iostream>

#include "DenseMatrix.h"

DenseMatrix::DenseMatrix(const std::vector<std::vector<double>> initialData){

    rows = initialData.size();

    size_t colTmp = initialData[0].size();

    for (int i=1; i<rows; i++){
        if (initialData[i].size() != colTmp){
            throw DenseMatrixExceptions("Error: Invalid matrix structure!");
        }
    }

    cols = colTmp;
    
    if (!initialData.empty()){
        // would probably be good to add a check that column and rows are equal
        // throw a custom exception here if the number of rows in the data don't match the data
        std::vector<double> flattenedData;
        for (const std::vector<double>& iRow: initialData){
            flattenedData.insert(flattenedData.end(), iRow.begin(), iRow.end());
        }
        *data_ = flattenedData;
    }
};

DenseMatrix::~DenseMatrix(){
    delete data_;
}

size_t DenseMatrix::numRows() const{ 
    return this->rows;
}

size_t DenseMatrix::numCols() const{
    return this->cols;
}

std::vector<double> DenseMatrix::getData() const{
    return *data_;
}

double& DenseMatrix::operator()(int row, int col){

    // Setting overload
    if ((row < 0) || (col < 0) || (row >= this->numRows()) || (col >= this->numCols())){
        throw DenseMatrixExceptions("Index Error: Out of bounds!");
    }
    return (*data_)[row*this->numCols()+col];
}

const double& DenseMatrix::operator()(int row, int col) const{

    // Access overload
    if ((row < 0) || (col < 0) || (row >= this->numRows()) || (col >= this->numCols())){
        throw DenseMatrixExceptions("Index Error: Out of bounds!");
    }
    return (*data_)[row*this->numCols()+col];
}

std::ostream& operator<<(std::ostream& os, const DenseMatrix& denseMat){
    
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