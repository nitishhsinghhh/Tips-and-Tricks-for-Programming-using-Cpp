cmake_minimum_required(VERSION 3.14)
project(StringConversion)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

# ---------------------------
# Include directories
# ---------------------------
include_directories(include)

# ---------------------------
# Main Application
# ---------------------------
add_executable(app
    src/sourcecode.cpp
    src/ProcessString.cpp
    src/LowerCaseConversion.cpp
    src/UpperCaseConversion.cpp
    src/CapitalizeWordsConversion.cpp
    src/SentenceCaseConversion.cpp
    src/ToggleCaseConversion.cpp
    src/StringConversionFactory.cpp
    src/Client.cpp
)

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
add_executable(runTests
    tests/StringConversionTests.cpp
    tests/AdvancedStringConversionTests.cpp
    src/ProcessString.cpp
    src/LowerCaseConversion.cpp
    src/UpperCaseConversion.cpp
    src/CapitalizeWordsConversion.cpp
    src/SentenceCaseConversion.cpp
    src/ToggleCaseConversion.cpp
    src/StringConversionFactory.cpp
    src/Client.cpp
)

target_link_libraries(runTests gtest gtest_main)

add_test(NAME AllTests COMMAND runTests)