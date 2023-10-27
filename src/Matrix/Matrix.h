#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <vector>

class Matrix{
    
    public:
        
        virtual size_t numRows() const=0;
        virtual size_t numCols() const=0;
        virtual std::vector<double> getData() const=0;

    
};

#endif