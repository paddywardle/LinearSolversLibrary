cmake_minimum_required(VERSION 3.4)
project(pybindTest)
add_subdirectory(pybind11)

set (DenseVectorSrc "../src/Vector/DenseVector.cpp")
set (DenseVectorBinding "Vector/DenseVector_binding.cpp")

pybind11_add_module(LinSol ${DenseVectorBinding} ${DenseVectorSrc})

# add_library(DenseVector SHARED DenseVector.cpp)