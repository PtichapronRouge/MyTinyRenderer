CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

set(CMAKE_BUILD_TYPE debug)

project(MyTinyRenderer)

#======================================================================

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(
    -Wall
    -Wextra
    -pedantic
    -g
)

#======================================================================

foreach(module IN ITEMS src/tga)
    add_subdirectory(${module})
endforeach()

add_executable(Renderer main.cpp)
target_link_libraries(Renderer PUBLIC tga)
target_include_directories(Renderer PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/tga"
)
