#include "SparseVector.h"

struct VectorProxy{

    SparseVector<SparseTypes::IDX>& Vector;
    int idx;

    VectorProxy(SparseVector<SparseTypes::IDX>& v, int i): Vector(v), idx(i){};

    SparseVector<SparseTypes::IDX>& operator=(double val){

        if (val == 0.0){
            auto it = Vector.data_.find(idx);
            if (it != Vector.data_.end()){
                Vector.data_.erase(it);
            }
            return this->Vector;
        }

        Vector.data_[idx] = val;
        return this->Vector;

    };

    SparseVector<SparseTypes::IDX>& operator+=(double val){
        
        if (val != 0.0){
            Vector.data_[idx] += val;
        }
        return this->Vector;
    };

    SparseVector<SparseTypes::IDX>& operator-=(double val){
        
        if (val != 0.0){
            Vector.data_[idx] -= val;
        }

        return this->Vector;
    };


    SparseVector<SparseTypes::IDX>& operator*=(double val){
        
        if (val != 0.0){
            Vector.data_[idx] *= val;
        }

        return this->Vector;
    };

    SparseVector<SparseTypes::IDX>& operator/=(double val){
        
        if (val != 0.0){
            Vector.data_[idx] /= val;
        }

        return this->Vector;
    };

    double operator*(double val){
        
        double returnVal;
        
        if (val != 0.0){
            returnVal = Vector.data_[idx] * val;
        }

        return returnVal;
    };

    double operator-(double val){
        
        double returnVal;
        
        if (val != 0.0){
            returnVal = Vector.data_[idx] - val;
        }

        return returnVal;
    };

    double operator/(double val){
        
        double returnVal;
        
        if (val != 0.0){
            returnVal = Vector.data_[idx] / val;
        }

        return returnVal;
    };

    double operator+(double val){
        
        double returnVal;
        
        if (val != 0.0){
            returnVal = Vector.data_[idx] + val;
        }

        return returnVal;
    };

    double getIdx(){
        return this->idx;
    }
    
    double getVal(){
        return this->Vector.data_[idx];
    }

    operator double() const{
        return this->Vector.data_[idx];
    }

    operator int() const{
        return this->Vector.data_[idx];
    }

    std::ostream& operator<<(std::ostream& os){
        os<<Vector.data_[idx]<<"\n";
        return os;
    }
};