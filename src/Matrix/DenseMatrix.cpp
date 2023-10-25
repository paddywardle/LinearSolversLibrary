#include "DenseMatrix.h"

DenseMatrix::DenseMatrix(size_t numRows, size_t numCols, const std::vector<std::vector<double>> initialData)
    :Matrix(numRows, numCols), data_(numRows, std::vector<double>(numCols, 0)) 
    {
        if (!initialData.empty()){
            // would probably be good to add a check that column and rows are equal
            data_ = initialData;
        }
};

std::vector<std::vector<double>> DenseMatrix::getData() const{
    return this->data_;
}
