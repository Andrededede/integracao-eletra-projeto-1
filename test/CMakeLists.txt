add_library(Catch INTERFACE ../test/)

add_executable(
    ${PROJECT_NAME}_test

    CatchMain.cpp
    MakerTest.cpp
    MeterTest.cpp
)

target_link_libraries(${PROJECT_NAME}_test
    Catch
    ${PROJECT_NAME}_lib
)

target_include_directories(
    ${PROJECT_NAME}_test PUBLIC "${PROJECT_SOURCE_DIR}/test/"
)