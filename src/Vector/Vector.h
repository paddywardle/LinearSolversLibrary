#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <vector>

class Vector{
    
    public:
        
        virtual size_t getLen() const=0;
        virtual std::vector<double> getData() const=0;
    
};

#endif