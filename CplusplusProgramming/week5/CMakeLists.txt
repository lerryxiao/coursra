cmake_minimum_required(VERSION 3.6)
project(week5)

set(CMAKE_CXX_STANDARD 98)

#set(SOURCE_FILES  src/wow_copy.cpp)
set(SOURCE_FILES  src/wow.cpp)

add_executable(week5 ${SOURCE_FILES})
