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
    src/AlternatingCaseConversion.cpp
    src/CapitalizeWordsConversion.cpp
    src/Client.cpp
    src/InvertWordsConversion.cpp
    src/KebabCaseConversion.cpp
    src/LeetSpeakConversion.cpp
    src/LowerCaseConversion.cpp
    src/ProcessString.cpp
    src/RemoveSpacesConversion.cpp
    src/RemoveVowelsConversion.cpp
    src/ReverseConversion.cpp
    src/SentenceCaseConversion.cpp
    src/SnakeCaseConversion.cpp
    src/StringConversionFactory.cpp
    src/ToggleCaseConversion.cpp
    src/UpperCaseConversion.cpp    
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
