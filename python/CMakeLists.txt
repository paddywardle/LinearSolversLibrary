cmake_minimum_required(VERSION 3.4)
project(pybindTest)

add_subdirectory(pybind11)

add_subdirectory(LinearSolvers)
add_subdirectory(MatOps)
add_subdirectory(Matrix)
add_subdirectory(Residuals)
add_subdirectory(VecOps)
add_subdirectory(Vector)
add_subdirectory(subLibrary)

set (DenseVectorSrc "../src/Vector/DenseVector.cpp")

set (DenseMatrixSrc "../src/Vector/DenseVector.cpp")

set (LinSol "linSol.cpp")

pybind11_add_module(LinSol 
                    ${LinSol}
                    ${VectorBindings} 
                    ${MatrixBindings} 
                    ${MatOpsBindings} 
                    ${VecOpsBindings} 
                    ${ResidualsBindings} 
                    ${LinearSolversBindings}

                    ${DenseVectorSrc} 
                    ${DenseMatrixSrc} 
                    ${MatOpsSrc} 
                    ${VecOpsSrc} 
                    ${ResidualsSrc} 
                    ${LinearSolversSrc}
)