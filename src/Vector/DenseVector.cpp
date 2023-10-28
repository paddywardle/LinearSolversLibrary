#include "DenseVector.h"

DenseVector::DenseVector(const std::vector<double> initialData){
        length = initialData.size();
        *data_ = initialData;
}

DenseVector::~DenseVector(){
    delete data_;
}

size_t DenseVector::getLen() const{ 
    return this->length;
}

std::vector<double> DenseVector::getData() const{
    return *data_;
}

std::ostream& operator<<(std::ostream& os, const DenseVector& denseVec){
    
    int vecLen = denseVec.getLen();

    const std::vector<double>& vecData = denseVec.getData();

    for (int i=0; i<vecLen; i++){
            os<<vecData[i]<<" ";
        }
        os<<"\n";

    return os;
}