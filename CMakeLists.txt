cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(
    Projeto1 
    VERSION 1.0
)



add_executable(
    ${PROJECT_NAME}

    source/main.cpp 
    source/Meter.cpp
    source/Line.cpp 
    source/Maker.cpp
)
    
    
target_include_directories(
    ${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include"
)