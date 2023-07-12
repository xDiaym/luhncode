cmake_minimum_required(VERSION 3.26)
project(luhnode_tests LANGUAGES CXX)

file(GLOB_RECURSE SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} luhncode gtest gtest_main)


enable_testing()
add_test(${PROJECT_NAME} ${SOURCES})
