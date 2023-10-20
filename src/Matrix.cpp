#include "Matrix.h"

Matrix::Matrix(size_t numRows, size_t numCols)
    :rows(numRows), cols(numCols) {}

size_t Matrix::numRows() const{
    return this->rows;
}

size_t Matrix::numCols() const{
    return this->cols;
}