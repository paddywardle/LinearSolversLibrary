set(MATRIX_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/DenseMatrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.cpp
)

add_subdirectory(Sparse)

target_sources(LinSol PRIVATE ${MATRIX_FILES})