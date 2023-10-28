#include "DenseVector.h"

DenseVector::DenseVector(const std::vector<double> initialData)
    :data_(initialData){
        length = initialData.size();
    };

size_t DenseVector::getLen() const{ 
    return this->length;
}

std::vector<double> DenseVector::getData() const{
    return this->data_;
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