cmake_minimum_required(VERSION 3.7)
project(Matrix)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp Matrix.h)
add_executable(Matrix main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(Matrix core)