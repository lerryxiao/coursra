cmake_minimum_required(VERSION 3.2.2)
project(week4)

set(CMAKE_CXX_STANDARD 11)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} )

set(SOURCE_FILES  ${PROJECT_SOURCE_DIR}/src/program4.cpp src/program4Test.cpp)

add_executable(week4 ${SOURCE_FILES})
target_link_libraries(week4 ${GTEST_BOTH_LIBRARIES})