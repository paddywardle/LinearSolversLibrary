set(READER_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/file_reader.cpp
)

target_sources(LinSol PRIVATE ${READER_FILES})