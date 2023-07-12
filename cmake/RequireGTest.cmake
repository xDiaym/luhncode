set(BENCHMARK_ENABLE_TESTING NO)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        TIMEOUT 10
        GIT_TAG v1.13.0
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/third_party/googletest
)

FetchContent_MakeAvailable(googletest)
