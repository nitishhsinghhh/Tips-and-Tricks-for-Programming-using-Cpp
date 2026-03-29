cmake_minimum_required(VERSION 3.14)
project(StringConversion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

# ---------------------------
# Include directories
# ---------------------------
include_directories(include)

# ---------------------------
# Library: StringConversionLib
# ---------------------------
add_library(StringConversionLib
    src/ProcessString.cpp
    src/LowerCaseConversion.cpp
    src/UpperCaseConversion.cpp
    src/CapitalizeWordsConversion.cpp
    src/SentenceCaseConversion.cpp
    src/AlternatingCaseConversion.cpp 
    src/ToggleCaseConversion.cpp
    src/StringConversionFactory.cpp
    src/Client.cpp
)

target_include_directories(StringConversionLib PUBLIC include)

# ---------------------------
# Main Application
# ---------------------------
add_executable(app src/sourcecode.cpp)
target_link_libraries(app StringConversionLib)

# ---------------------------
# GoogleTest Setup
# ---------------------------
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/main.zip
)

# Make GoogleTest available
FetchContent_MakeAvailable(googletest)

# ---------------------------
# Test Executable
# ---------------------------
add_executable(runTests
    tests/StringConversionTests.cpp
    tests/AdvancedStringConversionTests.cpp
)

# Link the library and GoogleTest
target_link_libraries(runTests StringConversionLib gtest gtest_main)

# ---------------------------
# Register tests with CTest
# ---------------------------
add_test(NAME AllTests COMMAND runTests)
