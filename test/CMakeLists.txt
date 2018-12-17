add_executable (dataFrameTest test.cpp)

target_include_directories (dataFrameTest PUBLIC ${DataFrame_SOURCE_DIR}/inc)
target_link_libraries (dataFrameTest LINK_PUBLIC DataFrame)
