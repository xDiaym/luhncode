cmake_minimum_required(VERSION 3.26)
project(luhncode-benchmarks LANGUAGES CXX)

file(GLOB_RECURSE SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} luhncode benchmark::benchmark)
