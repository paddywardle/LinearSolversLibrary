set (OPS_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/MatOps.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sparse/MatOpsSparseIDX.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VecOps.cpp

)

add_subdirectory(Sparse)

target_sources(LinSol PRIVATE ${OPS_FILES})