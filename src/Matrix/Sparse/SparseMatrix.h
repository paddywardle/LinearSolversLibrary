#ifndef SparseMatrix_H
#define SparseMatrix_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

#include "../Matrix.h"
#include "../../utils/SparseTypes.h"
#include "../../Exceptions/DenseMatrixExceptions.h"
#include "../../utils/VectorHasher.h"

template<typename sparseMat>
struct MatrixProxy;

template<SparseTypes sparseType>
class SparseMatrix: public Matrix {

    private:
        int defaultZero = 0;
        size_t rows;
        size_t cols;

    public:
        
        // Instantiation
        SparseMatrix(const std::vector<std::vector<double>> data_={});
        ~SparseMatrix(){};
        
        // Access functions
        size_t numRows() const override;
        size_t numCols() const override;
        std::vector<double> getData() const override;

        // Overloads
        MatrixProxy<SparseMatrix<SparseTypes::IDX>> operator()(const int row, const int col);
        const double& operator()(const  int row, const int col) const;
        SparseMatrix<sparseType>& operator=(const SparseMatrix<sparseType>& mat);
        SparseMatrix<sparseType> operator*(const SparseMatrix<sparseType>& mat);
        friend std::ostream& operator<<(std::ostream& os, const SparseMatrix<sparseType>& sparseMat);

};

template<>
class SparseMatrix<SparseTypes::IDX>: public Matrix {

    private:
        double defaultZero = 0;
        size_t rows;
        size_t cols;
        std::unordered_map<std::vector<int>,double,VectorHasher> data_;

    public:
        
        // Instantiation
        SparseMatrix(const std::vector<std::vector<double>> data_={});
        ~SparseMatrix(){};
        
        // Access functions
        size_t numRows() const override;
        size_t numCols() const override;
        std::vector<double> getData() const override;
        std::vector<int> getColIdx() const;
        std::vector<int> getRowIdx() const;
        std::unordered_map<std::vector<int>,double,VectorHasher> getDataMap() const;
        double getIdxVal(const int row, const int col) const;

        // Alter functions
        void dropIdx(std::vector<int> rowCol);
        void setMat(const int& row_nums, const int& col_nums, const std::unordered_map<std::vector<int>,double,VectorHasher>& matMap);
        void setIdx(const int row, const int col, const double val);

        // Overloads
        MatrixProxy<SparseMatrix<SparseTypes::IDX>> operator()(const int row, const int col);
        const double& operator()(const  int row, const int col) const;
        SparseMatrix<SparseTypes::IDX>& operator=(const SparseMatrix& mat);
        SparseMatrix<SparseTypes::IDX> operator*(const SparseMatrix<SparseTypes::IDX>& mat);

        friend std::ostream& operator<<(std::ostream& os, const SparseMatrix<SparseTypes::IDX>& sparseMat){
            
            int matRows = sparseMat.numRows();
            int matCols = sparseMat.numCols();

            const std::vector<double>& matData = sparseMat.getData();

            for (int i=0; i<matRows; i++){
                for (int j=0; j<matCols; j++){
                    os<<sparseMat(i,j)<<" ";
                }
                os<<"\n";
            }

            return os;
        }

};

template<typename sparseMat>
struct MatrixProxy{

    sparseMat& Matrix;
    int row;
    int col;

    MatrixProxy(sparseMat& v, int row, int col);

    // Overloads
    void operator=(double val);
    void operator+=(double val);
    void operator-=(double val);
    void operator*=(double val);
    void operator/=(double val);
    double operator*(double val);
    double operator-(double val);
    double operator/(double val);
    double operator+(double val);

    // Access functions
    double getRow() const;
    double getCol() const;
    double getVal() const;

    // Type conversions
    operator double() const;
    operator int() const;

    friend std::ostream& operator<<(std::ostream& os, MatrixProxy<sparseMat> MatrixProxy){
    os<<MatrixProxy.getVal()<<"\n";
    return os;
}

};

#endif