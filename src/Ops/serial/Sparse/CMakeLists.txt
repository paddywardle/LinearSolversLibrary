set(SPARSE_OPS_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/MatOpsSparseIDX.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VecOpsSparseIDX.cpp
)

target_sources(LinSol PRIVATE ${SPARSE_OPS_FILES})