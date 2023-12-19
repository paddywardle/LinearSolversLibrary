#ifndef SparseVector_H
#define SparseVector_H

#include <vector>
#include <iostream>
#include <unordered_map>

#include "VectorProxy.h"
#include "../Vector.h"
#include "../../utils/SparseTypes.h"
#include "../../Exceptions/DenseVectorExceptions.h"

template<SparseTypes sparseType>
class SparseVector: public Vector {

    private:
        int defaultZero = 0;
        size_t length;
        // friend struct VectorProxy;

        // struct VectorProxy{

        //     SparseVector<sparseType>& Vector;
        //     int idx;

        //     VectorProxy(SparseVector<sparseType>& v, int i);

        //     VectorProxy operator=(double val);

        //     VectorProxy operator+=(double val);

        //     VectorProxy operator-=(double val);

        //     double operator+(double val);
        //     double operator-(double val);
        // };

    public:
        
        // Instantiation
        SparseVector(const std::vector<double> data_={});
        ~SparseVector(){};
        
        // Access functions
        size_t getLen() const override;
        std::vector<double> getData() const override;
        std::vector<int> getIdx() const;

        // Overloads
        VectorProxy& operator()(const int idx);
        const double& operator()(const int idx) const;
        SparseVector<sparseType>& operator=(const SparseVector<sparseType>& vec);
        SparseVector<sparseType> operator*(const SparseVector<sparseType>& vec);
        friend std::ostream& operator<<(std::ostream& os, const SparseVector<sparseType>& sparseVec);

};

template<>
class SparseVector<SparseTypes::IDX>: public Vector {

    private:
        double defaultZero = 0;
        size_t length;
        std::unordered_map<int,double> data_;

        friend struct VectorProxy;

    public:
        
        // Instantiation
        SparseVector(const std::vector<double> data_={});
        ~SparseVector(){};
        
        // Access functions
        size_t getLen() const override;
        std::vector<double> getData() const override;
        std::vector<int> getIdx() const;
        std::unordered_map<int,double> getDataMap() const;

        // Alter functions
        void dropIdx(const int Idx);
        void setVec(const int& length, const std::unordered_map<int,double>& vecMap);

        // Overloads
        VectorProxy operator()(const int idx);
        double const& operator()(const int idx) const;
        SparseVector<SparseTypes::IDX>& operator=(const SparseVector& vec);
        SparseVector<SparseTypes::IDX> operator*(const SparseVector<SparseTypes::IDX>& vec);
        friend std::ostream& operator<<(std::ostream& os, const SparseVector<SparseTypes::IDX>& sparseVec);

};

#endif