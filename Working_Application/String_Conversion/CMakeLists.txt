cmake_minimum_required(VERSION 3.14)
project(StringConversion)

set(CMAKE_CXX_STANDARD 17)

# Enable testing
enable_testing()

# Download GoogleTest automatically
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/main.zip
)

FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(runTests StringConversionTests.cpp)

# Include headers
target_include_directories(runTests PRIVATE ${PROJECT_SOURCE_DIR})

# Link GoogleTest
target_link_libraries(runTests gtest gtest_main)

# Register test
add_test(NAME AllTests COMMAND runTests)