#ifndef VECTORPROXY_H
#define VECTORPROXY_H

#include "SparseVector.h"

template<typename sparseVec>
struct VectorProxy{

    sparseVec& Vector;
    int idx;

    VectorProxy(sparseVec& v, int i) : Vector(v), idx(i) {}

    sparseVec operator=(double val){

        if (val == 0.0){
            Vector.dropIdx(this->idx);
            return this->Vector;
        }
        Vector.setIdx(this->idx, val);

        return this->Vector;

    };

    sparseVec operator+=(double val){
        
        if (val != 0.0){
            val += Vector.getIdxVal(this->idx);
            Vector.setIdx(this->idx, val);
        }
        return this->Vector;
    };

    sparseVec operator-=(double val){
        
        if (val != 0.0){
            val -= Vector.getIdxVal(this->idx);
            Vector.setIdx(this->idx, val);
        }
        return this->Vector;
    };


    sparseVec operator*=(double val){
        
        if (val != 0.0){
            val *= Vector.getIdxVal(this->idx);
            Vector.setIdx(this->idx, val);
        }
        return this->Vector;
    };

    sparseVec operator/=(double val){
        
        if (val != 0.0){
            val /= Vector.getIdxVal(this->idx);
            Vector.setIdx(this->idx, val);
        }
        return this->Vector;
    };

    double operator*(double val){
        return Vector.getIdxVal(this->idx) * val;
    };

    double operator-(double val){
        return Vector.getIdxVal(this->idx) - val;
    };

    double operator/(double val){
        return Vector.getIdxVal(this->idx) / val;
    };

    double operator+(double val){
        return Vector.getIdxVal(this->idx) + val;
    };

    double getIdx(){
        return this->idx;
    }
    
    double getVal(){
        return Vector.getIdxVal(this->idx);
    }

    operator double() const{
        return Vector.getIdxVal(this->idx);
    }

    operator int() const{
        return Vector.getIdxVal(this->idx);
    }

    // std::ostream& operator<<(std::ostream& os){
    //     os<<Vector.getIdxVal(this->idx)<<"\n";
    //     return os;
    // }
};

#endif