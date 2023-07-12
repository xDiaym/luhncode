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

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)

option(LUHNCODE_BUILD_BENCHMARKS "Enable benchmarking" ON)
if (LUHNCODE_BUILD_BENCHMARKS)
    message(STATUS "Benchmarks: enabled")
    include(cmake/RequireGBench.cmake)
    add_subdirectory(bench)
else ()
    message(STATUS "Benchmarks: disabled")
endif ()

