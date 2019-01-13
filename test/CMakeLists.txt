find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_SET_1 "${CMAKE_CURRENT_SOURCE_DIR}/data/testSet1.txt" CACHE FILEPATH "Full path of the file")
file(TO_CMAKE_PATH "${TEST_SET_1}" TEST_SET_1_NORMALIZED)
add_definitions(-DTEST_SET_1="${TEST_SET_1_NORMALIZED}")

add_executable (dataFrameTest dataFrameTest.cpp)

target_include_directories (dataFrameTest PUBLIC ${DataFrame_SOURCE_DIR}/inc)
target_link_libraries (dataFrameTest DataFrame ${GTEST_LIBRARIES} pthread)
