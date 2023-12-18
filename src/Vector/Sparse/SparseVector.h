#ifndef SparseVector_H
#define SparseVector_H

#include <vector>
#include <iostream>
#include <unordered_map>

#include "../Vector.h"
#include "../../utils/SparseTypes.h"
#include "../../Exceptions/DenseVectorExceptions.h"

template<SparseTypes sparseType>
class SparseVector: public Vector {

    private:
        int defaultZero = 0;
        size_t length;

        struct VectorProxy{

            SparseVector<sparseType>& Vector;
            int idx;

            VectorProxy(SparseVector<sparseType>& v, int i);

            VectorProxy operator=(double val);

            VectorProxy operator+=(double val);

            VectorProxy operator-=(double val);

            double operator+(double val);
            double operator-(double val);
        };

    public:
        
        // Instantiation
        SparseVector(const std::vector<double> data_={});
        ~SparseVector(){};
        
        // Access functions
        size_t getLen() const override;
        std::vector<double> getData() const override;
        std::vector<int> getIdx() const;

        // Overloads
        VectorProxy& operator()(const int idx);
        const double& operator()(const int idx) const;
        SparseVector<sparseType>& operator=(const SparseVector<sparseType>& vec);
        SparseVector<sparseType> operator*(const SparseVector<sparseType>& vec);
        friend std::ostream& operator<<(std::ostream& os, const SparseVector<sparseType>& sparseVec);

};

template<>
class SparseVector<SparseTypes::IDX>: public Vector {

    private:
        double defaultZero = 0;
        size_t length;
        std::unordered_map<int,double> data_;

        struct VectorProxy{

            SparseVector<SparseTypes::IDX>& Vector;
            int idx;

            VectorProxy(SparseVector<SparseTypes::IDX>& v, int i);

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

            std::ostream& operator<<(std::ostream& os){
                os<<Vector.data_[idx]<<"\n";
                return os;
            }
        };

    public:
        
        // Instantiation
        SparseVector(const std::vector<double> data_={});
        ~SparseVector(){};
        
        // Access functions
        size_t getLen() const override;
        std::vector<double> getData() const override;
        std::vector<int> getIdx() const;
        std::unordered_map<int,double> getDataMap() const;

        // Alter functions
        void dropIdx(const int Idx);
        void setVec(const int& length, const std::unordered_map<int,double>& vecMap);

        // Overloads
        VectorProxy operator()(const int idx);
        double const& operator()(const int idx) const;
        SparseVector<SparseTypes::IDX>& operator=(const SparseVector& vec);
        SparseVector<SparseTypes::IDX> operator*(const SparseVector<SparseTypes::IDX>& vec);
        friend std::ostream& operator<<(std::ostream& os, const SparseVector<SparseTypes::IDX>& sparseVec);

};

#endif