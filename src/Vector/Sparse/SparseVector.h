#ifndef SPARSEVECTOR_H
#define SPARSEVECTOR_H

#include <vector>
#include <iostream>
#include <unordered_map>

#include "../Vector.h"
#include "../../utils/SparseTypes.h"
#include "../../Exceptions/DenseVectorExceptions.h"

template<typename sparseVec>
struct VectorProxy;

template<SparseTypes sparseType>
class SparseVector: public Vector {

    private:
        int defaultZero = 0;
        size_t length;

    public:
        
        // Instantiation
        SparseVector(const std::vector<double> data_={});
        ~SparseVector(){};
        
        // Access functions
        size_t getLen() const override;
        std::vector<double> getData() const override;
        std::vector<int> getIdx(const int idx) const;
        double getIdxVal(const int idx) const;

        // Alter functions
        void setIdx(const int idx, const double val);

        // Overloads
        VectorProxy<SparseVector<sparseType>> operator()(const int idx);
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

    public:
        
        // Instantiation
        SparseVector(const std::vector<double> data_={});
        ~SparseVector(){};
        
        // Access functions
        size_t getLen() const override;
        std::vector<double> getData() const override;
        std::vector<int> getIdx() const;
        std::unordered_map<int,double> getDataMap() const;
        double getIdxVal(const int idx) const;

        // Alter functions
        void dropIdx(const int Idx);
        void setVec(const int& length, const std::unordered_map<int,double>& vecMap);
        void setIdx(const int idx, const double val);

        // Overloads
        VectorProxy<SparseVector<SparseTypes::IDX>> operator()(const int idx);
        double const& operator()(const int idx) const;
        SparseVector<SparseTypes::IDX>& operator=(const SparseVector& vec);
        SparseVector<SparseTypes::IDX> operator*(const SparseVector<SparseTypes::IDX>& vec);
        friend std::ostream& operator<<(std::ostream& os, const SparseVector<SparseTypes::IDX>& sparseVec);

};

template<typename sparseVec>
struct VectorProxy{

    sparseVec& Vector;
    int idx;

    VectorProxy(sparseVec& v, int i);

    // Overloads
    void operator=(double val);
    void operator+=(double val);
    void operator-=(double val);
    void operator*=(double val);
    void operator/=(double val);
    double operator*(double val);
    double operator-(double val);
    double operator/(double val);
    double operator+(double val);

    // Access functions
    double getIdx();
    double getVal();

    // Type conversions
    operator double() const;
    operator int() const;

    friend std::ostream& operator<<(std::ostream& os, VectorProxy<sparseVec> vectorProxy);
};

#endif