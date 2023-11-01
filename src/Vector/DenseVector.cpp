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

double& DenseVector::operator()(int i){

    // Setting overload
    if ((i < 0) || (i >= this->getLen())){
        throw DenseVectorExceptions("Index Error: Out of bounds!");
    }
    return (*data_)[i];
}

const double& DenseVector::operator()(int i) const{

    // Access overload
    if ((i < 0) || (i >= this->getLen())){
        throw DenseVectorExceptions("Index Error: Out of bounds!");
    }
    return (*data_)[i];
}

DenseVector& DenseVector::operator=(const DenseVector& vec){

    if (this != &vec){
        (*data_) = vec.getData();
        length = vec.getLen();
    }

    return *this;

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