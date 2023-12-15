// #include "SparseVector.h"

// // template<typename vec>
// struct SparseVector<SparseTypes::IDX>::VectorProxy{

//     SparseVector<SparseTypes::IDX>& Vector;
//     int idx;

//     VectorProxy(SparseVector<SparseTypes::IDX>& v, int i): Vector(v), idx(i){};

//     VectorProxy& operator=(double val){

//         if (val == 0.0){
//             auto it = Vector.data_.find(idx);
//             if (it != Vector.data_.end()){
//                 Vector.data_.erase(it);
//             }
//             return *this;
//         }

//         Vector.data_[idx] = val;
//         return *this;

//     }
// };