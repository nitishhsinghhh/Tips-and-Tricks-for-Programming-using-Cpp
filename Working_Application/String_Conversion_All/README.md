# Refactored Design (SOLID)

This project demonstrates a clean C++ design using SOLID principles
and modern C++ practices.

| Principle | Fix |
| --- | --- |
| SRP (Single Responsibility Principle) | Separate conversion logic, factory creation, and client usage into different classes |
| OCP (Open/Closed Principle) | Add new conversion classes without modifying existing switch/conditional logic |
| DIP (Dependency Inversion Principle) | Depend on abstractions (interfaces/abstract classes) instead of concrete implementations |
| RAII (Resource Acquisition Is Initialization) | Use std::unique_ptr for automatic memory management and resource safety |

## File Structure

StringConversion/
│
├── include/
│   ├── IStringConversion.hpp
│   ├── LowerCaseConversion.hpp
│   ├── StringConversionFactory.hpp
│   └── Client.hpp
│
├── src/
│   └── main.cpp
│
├── tests/
│   └── StringConversionTests.cpp
│
├── build/
│
└── CMakeLists.txt

## Build Instructions

### Configure

cmake -S . -B build

### Build

cmake --build build

### Run App

./build/app

### Run Tests

cd build
ctest --output-on-failure

### Manual Compile (Optional)

g++ -std=c++17 -Iinclude src/sourcecode.cpp -o app
./app

### Adding a New Conversion Type

1. Create new class implementing IStringConversion

2. Update Factory:

```Cpp
case ConversionType::Reverse:
    return std::make_unique<ReverseCaseConversion>();
```

3. Update ProcessString.cpp mapping

4. Update CMakeLists.txt:

src/ReverseCaseConversion.cpp

5. Rebuild:
cmake --build build

6. Add unit tests

```cpp
#include <gtest/gtest.h>
#include "TestHelpers.hpp"
#include "IStringConversion.hpp"
#include "LowerCaseConversion.hpp"
#include "UpperCaseConversion.hpp"
#include "CapitalizeWordsConversion.hpp"
#include "SentenceCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "AlternatingCaseConversion.hpp"  
#include "ReverseConversion.hpp"
#include "StringConversionFactory.hpp"
#include "Client.hpp"
#include "ProcessString.hpp"
#include <iostream>
```
