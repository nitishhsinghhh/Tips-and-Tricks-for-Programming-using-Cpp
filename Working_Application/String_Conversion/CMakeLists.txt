cmake_minimum_required(VERSION 3.14)
project(StringConversion)

# ---------------------------
# C++ standard
# ---------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------------------
# Enable testing
# ---------------------------
enable_testing()

# ---------------------------
# Include directories
# ---------------------------
include_directories(include)

# ---------------------------
# Source files
# ---------------------------
set(SRC_FILES
    src/CapitalizeWordsConversion.cpp
    src/Client.cpp 
    src/helpers.cpp
    src/LowerCaseConversion.cpp
    src/SentenceCaseConversion.cpp
    src/sourcecode.cpp
    src/StringConversionFactory.cpp
    src/ToggleCaseConversion.cpp
    src/UpperCaseConversion.cpp
)

# ---------------------------
# Main Application
# ---------------------------
add_executable(app ${SRC_FILES})

# ---------------------------
# GoogleTest Setup
# ---------------------------
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/main.zip
)

FetchContent_MakeAvailable(googletest)

# ---------------------------
# Tests
# ---------------------------
set(TEST_FILES
    tests/StringConversionTests.cpp
)

add_executable(runTests ${TEST_FILES})

target_link_libraries(runTests gtest gtest_main)

add_test(NAME AllTests COMMAND runTests)