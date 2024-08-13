cmake_minimum_required(VERSION 3.29)
project(
    Matrix
    VERSION 0.0.1
    DESCRIPTION "Matrix class"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

add_executable(Matrix_class)

set(sources
    src/main.cpp
    src/Matrix.h
    src/Matrix.cpp    
)

target_sources(Matrix_class PRIVATE ${sources})

#Укажем директиву, которая будет указывать о включении директории в директорию сборки
target_include_directories(Matrix_class
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)