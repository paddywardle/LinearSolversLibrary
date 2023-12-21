#include "SparseVector.h"

template<typename sparseVec>
VectorProxy<sparseVec>::VectorProxy(sparseVec& v, int i) : Vector(v), idx(i) {};

template<typename sparseVec>
void VectorProxy<sparseVec>::operator=(double val){

    if (val == 0.0){
        Vector.dropIdx(this->idx);
        
    }
    Vector.setIdx(this->idx, val);

};

template<typename sparseVec>
void VectorProxy<sparseVec>::operator+=(double val){
    
    if (val != 0.0){
        val += Vector.getIdxVal(this->idx);
        Vector.setIdx(this->idx, val);
    }
    
};

template<typename sparseVec>
void VectorProxy<sparseVec>::operator-=(double val){
    
    if (val != 0.0){
        val -= Vector.getIdxVal(this->idx);
        Vector.setIdx(this->idx, val);
    }
    
};

template<typename sparseVec>
void VectorProxy<sparseVec>::operator*=(double val){
    
    if (val != 0.0){
        val *= Vector.getIdxVal(this->idx);
        Vector.setIdx(this->idx, val);
    }
    
};

template<typename sparseVec>
void VectorProxy<sparseVec>::operator/=(double val){
    
    if (val != 0.0){
        val /= Vector.getIdxVal(this->idx);
        Vector.setIdx(this->idx, val);
    }
    
};

template<typename sparseVec>
double VectorProxy<sparseVec>::operator*(double val){
    return Vector.getIdxVal(this->idx) * val;
};

template<typename sparseVec>
double VectorProxy<sparseVec>::operator-(double val){
    return Vector.getIdxVal(this->idx) - val;
};

template<typename sparseVec>
double VectorProxy<sparseVec>::operator/(double val){
    return Vector.getIdxVal(this->idx) / val;
};

template<typename sparseVec>
double VectorProxy<sparseVec>::operator+(double val){
    return Vector.getIdxVal(this->idx) + val;
};

template<typename sparseVec>
double VectorProxy<sparseVec>::getIdx(){
    return this->idx;
}

template<typename sparseVec>
double VectorProxy<sparseVec>::getVal(){
    return Vector.getIdxVal(this->idx);
}

template<typename sparseVec>
VectorProxy<sparseVec>::operator double() const{
    return Vector.getIdxVal(this->idx);
}

template<typename sparseVec>
VectorProxy<sparseVec>::operator int() const{
    return Vector.getIdxVal(this->idx);
}

template<typename sparseVec>
std::ostream& operator<<(std::ostream& os, VectorProxy<sparseVec> vectorProxy){
    os<<vectorProxy.Vector.getIdxVal(vectorProxy.idx)<<"\n";
    return os;
}

template struct VectorProxy<SparseVector<SparseTypes::IDX>>;