set (OPSOMP_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/MatOpsOMP.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VecOpsOMP.cpp
)

target_sources(LinSol PRIVATE ${OPSOMP_FILES})