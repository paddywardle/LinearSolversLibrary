#ifndef DENSEVECTOR_H
#define DENSEVECTOR_H

#include <vector>
#include <iostream>

#include "Vector.h"

class DenseVector: public Vector {

    private:
        size_t length;
        std::vector<double> data_;

    public:
        
        // Instantiation
        DenseVector(const std::vector<double> data_={});
        ~DenseVector(){};
        
        // Access functions
        size_t getLen() const override;
        std::vector<double> getData() const override;

        // Overloads
        friend std::ostream& operator<<(std::ostream& os, const DenseVector& denseVec);  

};

#endif