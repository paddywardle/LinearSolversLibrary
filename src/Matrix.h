#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>

class Matrix{

    private:
        size_t rows;
        size_t cols;
    public:

        Matrix(size_t numRows, size_t numCols);
        
        size_t numRows() const;
        size_t numCols() const;

};

#endif