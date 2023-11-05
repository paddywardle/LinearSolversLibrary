#ifndef DENSEVECTOR_H
#define DENSEVECTOR_H

#include <vector>
#include <iostream>

#include "Vector.h"
#include "../Exceptions/DenseVectorExceptions.h"

class DenseVector: public Vector {

    private:
        size_t length;
        std::vector<double> data_;

    public:
        
        // Instantiation
        DenseVector(const std::vector<double> data_);
        DenseVector();
        ~DenseVector(){};
        
        // Access functions
        size_t getLen() const override;
        std::vector<double> getData() const override;

        // Overloads
        double& operator()(const int i);
        const double& operator()(const int i) const;
        DenseVector& operator=(const DenseVector& vec);
        friend std::ostream& operator<<(std::ostream& os, const DenseVector& denseVec); 

};

#endif