#include "SparseVector.h"

// VectorProxy SparseVector<SparseTypes::IDX>::VectorProxy::operator=(double val){

//     if (val == 0.0){
//         auto it = Vector.data_.find(idx);
//         if (it != Vector.data_.end()){
//             Vector.data_.erase(it);
//         }
//         return *this;
//     }

//     Vector.data_[idx] = val;
//     return *this;

// }

// VectorProxy SparseVector<SparseTypes::IDX>::VectorProxy::operator+=(double val){
    
//     if (val != 0.0){
//         Vector.data_[idx] += val;
//     }

//     return *this;
// }

// VectorProxy SparseVector<SparseTypes::IDX>::VectorProxy::operator-=(double val){
    
//     if (val != 0.0){
//         Vector.data_[idx] -= val;
//     }

//     return *this;
// }

// double SparseVector<SparseTypes::IDX>::VectorProxy::operator+(double val){
    
//     if (val != 0.0){
//         return Vector.data_[idx] + val;
//     }
// }

// double SparseVector<SparseTypes::IDX>::VectorProxy::operator-(double val){
    
//     if (val != 0.0){
//         return Vector.data_[idx] - val;
//     }
// }

SparseVector<SparseTypes::IDX>::SparseVector(const std::vector<double> initialData){

    length = initialData.size();

    if (!initialData.empty()){
        for (int i=0; i<length; i++){
            if (initialData[i] != 0.0){
                data_[i] = initialData[i];
                }
            }
        }
};

size_t SparseVector<SparseTypes::IDX>::getLen() const{ 
    return this->length;
}

std::vector<double> SparseVector<SparseTypes::IDX>::getData() const{

    std::vector<double> values;

    for (const auto& value: this->data_){
        values.push_back(value.second);
    }

    return values;
}

std::vector<int> SparseVector<SparseTypes::IDX>::getIdx() const{

    std::vector<int> Indices;
    for (const auto& value: this->data_){
        Indices.push_back(value.first);
    }
    return Indices;
}

double SparseVector<SparseTypes::IDX>::getIdxVal(const int idx) const{

    auto it = this->data_.find(idx);

    // return ((it != this->data_.end()) ? it->second : 0);
    return 0;
    
}

std::unordered_map<int,double> SparseVector<SparseTypes::IDX>::getDataMap() const{
    return this->data_;
}

void SparseVector<SparseTypes::IDX>::dropIdx(const int Idx){

    auto it = this->data_.find(Idx);

    if (it != this->data_.end()){
        this->data_.erase(it);
    }
}

void SparseVector<SparseTypes::IDX>::setIdx(const int idx, const double val){
    this->data_[idx] = val;
}

void SparseVector<SparseTypes::IDX>::setVec(const int& length, const std::unordered_map<int,double>& vecMap){
    this->length = length;
    this->data_ = vecMap;
}

VectorProxy SparseVector<SparseTypes::IDX>::operator()(const int idx){

    // Setting overload
    if ((idx < 0) || (idx >= this->getLen())){
        throw DenseVectorExceptions("Index Error: Out of bounds!");
    }

    return VectorProxy(*this, idx);
}

double const& SparseVector<SparseTypes::IDX>::operator()(const int idx) const{

    // Access overload
    if ((idx < 0) || (idx >= this->getLen())){
        throw DenseVectorExceptions("Index Error: Out of bounds!");
    }

    auto it = this->data_.find(idx);

    if (it != this->data_.end()){
        return it->second;
    }

    return this->defaultZero;
}

SparseVector<SparseTypes::IDX>& SparseVector<SparseTypes::IDX>::operator=(const SparseVector<SparseTypes::IDX>& vec){

    // guard clause for if this = mat (Vector being fed in)
    // avoids unnecessary reallocation
    // CHANGE - need to put indices here!
    if (this != &vec){
        this->data_ = vec.getDataMap();
    }
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SparseVector<SparseTypes::IDX>& sparseVec){
    
    int vecLen = sparseVec.getLen();
    
    for (int i=0; i<vecLen; i++){
        os<<sparseVec(i)<<" ";
    }
    os<<"\n";

    return os;
}