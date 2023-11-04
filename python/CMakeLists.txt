cmake_minimum_required(VERSION 3.4)
project(pybindTest)
add_subdirectory(pybind11)

set (DenseVectorSrc "../src/Vector/DenseVector.cpp")
set (DenseVectorBinding "Vector/DenseVector_binding.cpp")

set (DenseMatrixSrc "../src/Matrix/DenseMatrix.cpp")
set (DenseMatrixBinding "Matrix/DenseMatrix_binding.cpp")

set (DVOpsSrc "../src/VecOps/DVOps.cpp")
set (DVOpsBinding "VecOps/DVOps_binding.cpp")

set (DMOpsSrc "../src/MatOps/DMOps.cpp")
set (DMOpsBinding "MatOps/DMOps_binding.cpp")

set (LinSol "LinSol_binding.cpp")

pybind11_add_module(Vector ${DenseVectorBinding} ${DenseVectorSrc})
pybind11_add_module(Matrix ${DenseMatrixBinding} ${DenseMatrixSrc})
pybind11_add_module(DVOps ${DVOpsBinding} ${DVOpsSrc})
pybind11_add_module(DMOps ${DMOpsBinding} ${DMOpsSrc})

pybind11_add_module(LinSol ${LinSol} ${DenseVectorSrc} ${DenseMatrixSrc} ${DVOpsSrc} ${DMOpsSrc})