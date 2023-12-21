#include "SparseMatrix.h"

template<typename sparseMat>
MatrixProxy<sparseMat>::MatrixProxy(sparseMat& v, int row, int col) : Matrix(v), row(row), col(col) {};

template<typename sparseMat>
void MatrixProxy<sparseMat>::operator=(double val){

    if (val == 0.0){
        Matrix.dropIdx({this->row, this->col});
        
    }
    Matrix.setIdx(this->row, this->col, val);

};

template<typename sparseMat>
void MatrixProxy<sparseMat>::operator+=(double val){
    
    if (val != 0.0){
        val += Matrix.getIdxVal(this->row,this->col);
        Matrix.setIdx(this->row,this->col,val);
    }
    
};

template<typename sparseMat>
void MatrixProxy<sparseMat>::operator-=(double val){
    
    if (val != 0.0){
        double valSub = Matrix.getIdxVal(this->row,this->col) - val;
        Matrix.setIdx(this->row,this->col,valSub);
    }
};

template<typename sparseMat>
void MatrixProxy<sparseMat>::operator*=(double val){
    
    if (val != 0.0){
        val *= Matrix.getIdxVal(this->row,this->col);
        Matrix.setIdx(this->row,this->col,val);
    }
    
};

template<typename sparseMat>
void MatrixProxy<sparseMat>::operator/=(double val){
    
    if (val != 0.0){
        double valDiv = Matrix.getIdxVal(this->row,this->col) / val;
        Matrix.setIdx(this->row,this->col,valDiv);
    }
    
};

template<typename sparseMat>
double MatrixProxy<sparseMat>::operator*(double val){
    return Matrix.getIdxVal(this->row,this->col) * val;
};

template<typename sparseMat>
double MatrixProxy<sparseMat>::operator-(double val){
    return Matrix.getIdxVal(this->row,this->col) - val;
};

template<typename sparseMat>
double MatrixProxy<sparseMat>::operator/(double val){
    return Matrix.getIdxVal(this->row,this->col) / val;
};

template<typename sparseMat>
double MatrixProxy<sparseMat>::operator+(double val){
    return Matrix.getIdxVal(this->row,this->col) + val;
};

template<typename sparseMat>
double MatrixProxy<sparseMat>::getRow() const{
    return this->row;
}

template<typename sparseMat>
double MatrixProxy<sparseMat>::getCol() const{
    return this->col;
}

template<typename sparseMat>
double MatrixProxy<sparseMat>::getVal() const{
    return Matrix.getIdxVal(this->row,this->col);
}

template<typename sparseMat>
MatrixProxy<sparseMat>::operator double() const{
    return Matrix.getIdxVal(this->row,this->col);
}

template<typename sparseMat>
MatrixProxy<sparseMat>::operator int() const{
    return Matrix.getIdxVal(this->row,this->col);
}

template struct MatrixProxy<SparseMatrix<SparseTypes::IDX>>;