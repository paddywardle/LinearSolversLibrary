set (OPS_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/MatOps.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sparse/MatOpsSparseIDX.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VecOps.cpp

)

target_sources(LinSol PRIVATE ${OPS_FILES})