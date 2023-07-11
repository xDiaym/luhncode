cmake_minimum_required(VERSION 3.26)
project(luna LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/RequireGBench.cmake)
add_compile_options(-mavx2 -mfma)
add_compile_options(-O2 -g)
add_executable(luna main.cpp)
target_link_libraries(luna benchmark::benchmark)
