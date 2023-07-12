cmake_minimum_required(VERSION 3.26)
project(luhncode LANGUAGES CXX)


option(LUHNCODE_NO_SIMD "Disable SIMD instruction support" OFF)
if (LUHNCODE_NO_SIMD)
    if (CMAKE_SYSTEM_PROCESSOR MATCHES "^x86")
        message(STATUS "SIMD: disabled")
    else ()
        message(FATAL_ERROR "SIMD: not supported, but enabled")
    endif ()
else ()
    message(STATUS "SIMD: enabled")
endif ()


include(cmake/CompilerOptions.cmake)
include(cmake/SetupCCache.cmake)
include(cmake/RequireGBench.cmake)

add_executable(${CMAKE_PROJECT_NAME} main.cpp include/luhncode.hpp)
target_link_libraries(${CMAKE_PROJECT_NAME} benchmark::benchmark)
