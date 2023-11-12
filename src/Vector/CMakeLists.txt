set(VECTOR_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/DenseVector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp
)

target_sources(LinSol PRIVATE ${VECTOR_FILES})