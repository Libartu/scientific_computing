
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable (dataFrameTest dataFrameTest.cpp)

target_include_directories (dataFrameTest PUBLIC ${DataFrame_SOURCE_DIR}/inc)
target_link_libraries (dataFrameTest DataFrame ${GTEST_LIBRARIES} pthread)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/datingTestSet.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
