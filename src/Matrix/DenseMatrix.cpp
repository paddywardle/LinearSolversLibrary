#include "DenseMatrix.h"

DenseMatrix::DenseMatrix(size_t numRows, size_t numCols, const std::vector<std::vector<double>> initialData){

    rows = numRows;
    cols = numCols;
    if (!initialData.empty()){
        // would probably be good to add a check that column and rows are equal
        // throw a custom exception here if the number of rows in the data don't match the data
        std::vector<double> flattenedData;
        for (const std::vector<double>& iRow: initialData){
            flattenedData.insert(flattenedData.end(), iRow.begin(), iRow.end());
        }
        data_ = flattenedData;
    }

    data_ = std::vector<double>(numRows*numCols, 0);
};

size_t DenseMatrix::numRows() const{ 
    return this->rows;
}

size_t DenseMatrix::numCols() const{
    return this->cols;
}

std::vector<double> DenseMatrix::getData() const{
    return this->data_;
}

DenseMatrix DenseMatrix::matMul(DenseMatrix& denseMatOther) const{

    if (this->numCols() == denseMatOther.numRows()){
        // needs to be a vector of vectors
        std::vector<double>resultFlat (this->numRows()*denseMatOther.numCols());

        for (int i=0; i<this->numRows(); i++){
            for (int j=0; j<denseMatOther.numCols(); i++){
                for (int k=0; k<this->numCols(); i++){
                    // make this look prettier (make sure it's correct)
                    resultFlat[i*denseMatOther.numCols()+j] += this->getData()[i*this->numCols()+k] * denseMatOther.getData()[k*denseMatOther.numCols()+j];
                }
            }
        }
        // need to actually put it as a vector of vector for the correct initialisation
        DenseMatrix denseMatResult(this->numRows(), denseMatOther.numCols(), resultFlat)
    }

    return 
}