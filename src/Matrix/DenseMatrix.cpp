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

DenseMatrix DenseMatrix::matMul(const DenseMatrix& denseMatOther) const{

    int matARows = this->numRows();
    int matACols = this->numCols();

    int matBRows = denseMatOther.numRows();
    int matBCols = denseMatOther.numCols();

    if (matACols == matBRows){
        // needs to be a vector of vectors
        std::vector<std::vector<double>>resultMat (matARows,std::vector<double>(matBCols,0));

        for (int i=0; i<matARows; i++){
            for (int j=0; j<matACols; i++){
                for (int k=0; k<matACols; i++){
                    // make this look prettier (make sure it's correct)
                    resultMat[i][j] += this->getData()[i*matACols+k]*denseMatOther.getData()[k*matBCols+j];
                }
            }
        }
        // need to actually put it as a vector of vector for the correct initialisation
        return DenseMatrix(this->numRows(), denseMatOther.numCols(), resultMat);
    }

}