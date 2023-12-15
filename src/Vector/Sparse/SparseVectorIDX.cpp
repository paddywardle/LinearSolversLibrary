#include <iostream>

#include "SparseVector.h"

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

std::unordered_map<int,double> SparseVector<SparseTypes::IDX>::getDataMap() const{
    return this->data_;
}

void SparseVector<SparseTypes::IDX>::dropIdx(const int Idx){

    auto it = this->data_.find(Idx);

    if (it != this->data_.end()){
        this->data_.erase(it);
    }
}

void SparseVector<SparseTypes::IDX>::setVec(const int& length, const std::unordered_map<int,double>& vecMap){
    this->length = length;
    this->data_ = vecMap;
}

double& SparseVector<SparseTypes::IDX>::operator()(const int idx){

    // Setting overload
    if ((idx < 0) || (idx >= this->getLen())){
        throw DenseVectorExceptions("Index Error: Out of bounds!");
    }

    auto it = this->data_.find(idx);

    if (it != this->data_.end()){
        return it->second;
    }
    
    return this->data_[idx];
}

const double& SparseVector<SparseTypes::IDX>::operator()(const int idx) const{

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