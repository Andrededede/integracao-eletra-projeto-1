cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(
    Projeto1
    VERSION 1.0
    )

add_library(
    ${PROJECT_NAME}_lib

    ${PROJECT_SOURCE_DIR}/source/Meter.cpp
    ${PROJECT_SOURCE_DIR}/source/Line.cpp
    ${PROJECT_SOURCE_DIR}/source/Maker.cpp
)

target_include_directories(
    ${PROJECT_NAME}_lib PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

add_executable(
    ${PROJECT_NAME}

    ${PROJECT_SOURCE_DIR}/source/main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}

    ${PROJECT_NAME}_lib
)

add_subdirectory(test)