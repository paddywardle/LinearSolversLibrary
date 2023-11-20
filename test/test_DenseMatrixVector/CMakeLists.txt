set(TEST_DENSEMATRIXVECTOR_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/test_DenseMatrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_DenseVector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_DMOps.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_DVOps.cpp
)

target_link_libraries(LinSol PRIVATE ${TEST_DENSEMATRIXVECTOR_FILES})

${CMAKE_BINARY_DIR}

${gtest_}