#include "SparseVector.h"

template <SparseTypes sparseType>
class SparseVector;

struct VectorProxy{

    SparseVector<SparseTypes::IDX>& Vector;
    int idx;

    VectorProxy(SparseVector<SparseTypes::IDX>& v, int i){
        Vector = v;
        idx = i;
    };

    SparseVector<SparseTypes::IDX> operator=(double val){

        if (val == 0.0){
            Vector.dropIdx(this->idx);
            return this->Vector;
        }
        Vector.setIdx(this->idx, val);

        return this->Vector;

    };

    SparseVector<SparseTypes::IDX> operator+=(double val){
        
        if (val != 0.0){
            val += Vector.getIdxVal(this->idx);
            Vector.setIdx(this->idx, val);
        }
        return this->Vector;
    };

    SparseVector<SparseTypes::IDX> operator-=(double val){
        
        if (val != 0.0){
            val -= Vector.getIdxVal(this->idx);
            Vector.setIdx(this->idx, val);
        }
        return this->Vector;
    };


    SparseVector<SparseTypes::IDX> operator*=(double val){
        
        if (val != 0.0){
            val *= Vector.getIdxVal(this->idx);
            Vector.setIdx(this->idx, val);
        }
        return this->Vector;
    };

    SparseVector<SparseTypes::IDX> operator/=(double val){
        
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

    std::ostream& operator<<(std::ostream& os){
        os<<Vector.getIdxVal(this->idx)<<"\n";
        return os;
    }
};