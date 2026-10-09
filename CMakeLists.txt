cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(
    Projeto1
    VERSION 1.0
    )

add_library(
    ${PROJECT_NAME}_lib

    ${PROJECT_SOURCE_DIR}/source/Maker.cpp
    ${PROJECT_SOURCE_DIR}/source/meter/MeterFactory.cpp
    ${PROJECT_SOURCE_DIR}/source/meter/Meter.cpp
    ${PROJECT_SOURCE_DIR}/source/meter/lines/Apolo.cpp
    ${PROJECT_SOURCE_DIR}/source/meter/lines/Ares.cpp
    ${PROJECT_SOURCE_DIR}/source/meter/lines/Cronos.cpp
    ${PROJECT_SOURCE_DIR}/source/meter/lines/Zeus.cpp
)

target_include_directories(
    ${PROJECT_NAME}_lib PUBLIC "${PROJECT_SOURCE_DIR}/include"
    ${PROJECT_NAME}_lib PUBLIC "${PROJECT_SOURCE_DIR}/include/meter"
    ${PROJECT_NAME}_lib PUBLIC "${PROJECT_SOURCE_DIR}/include/meter/lines"
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