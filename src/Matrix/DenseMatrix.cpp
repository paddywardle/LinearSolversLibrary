#include <iostream>

#include "DenseMatrix.h"
#include "../Exceptions/DenseMatrixExceptions.h"

DenseMatrix::DenseMatrix(const size_t numRows, const size_t numCols, const std::vector<std::vector<double>> initialData){

    rows = numRows;
    cols = numCols;
    
    if (!initialData.empty()){
        // would probably be good to add a check that column and rows are equal
        // throw a custom exception here if the number of rows in the data don't match the data
        std::vector<double> flattenedData;
        for (const std::vector<double>& iRow: initialData){
            flattenedData.insert(flattenedData.end(), iRow.begin(), iRow.end());
        }
        data_ = flattenedData;
    }
    else {
        data_ = std::vector<double>(numRows*numCols, 0);
    }
};

size_t DenseMatrix::numRows() const{ 
    return this->rows;
}

size_t DenseMatrix::numCols() const{
    return this->cols;
}

std::vector<double> DenseMatrix::getData() const{
    return this->data_;
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