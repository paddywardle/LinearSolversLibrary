set (RESIUALS_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/Residuals.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ResidualsOMP.cpp
)

target_sources(LinSol PRIVATE ${RESIUALS_FILES})