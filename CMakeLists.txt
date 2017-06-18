cmake_minimum_required(VERSION 3.5)
project(Matrix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES main.cpp Matrix.h)
add_executable(Matrix main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(Matrix core)