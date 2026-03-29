# Refactored Design (SOLID)

This project demonstrates a clean C++ design using SOLID principles and modern C++ practices.

| Principle | Fix |
| --- | --- |
| SRP (Single Responsibility Principle) | Separate conversion logic, factory creation, and client usage into different classes |
| OCP (Open/Closed Principle) | Add new conversion classes without modifying existing switch/conditional logic |
| DIP (Dependency Inversion Principle) | Depend on abstractions (interfaces/abstract classes) instead of concrete implementations |
| RAII (Resource Acquisition Is Initialization) | Use `std::unique_ptr` for automatic memory management and resource safety |

## File Structure

```
StringConversion/
│
├── include/
│   ├── IStringConversion.hpp
│   ├── LowerCaseConversion.hpp
│   ├── UpperCaseConversion.hpp
│   ├── CapitalizeWordsConversion.hpp
│   ├── SentenceCaseConversion.hpp
│   ├── ToggleCaseConversion.hpp
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
```

## Build Instructions

### Step 1: Configure project

```Bash
cmake -S . -B build
```

### Step 2: Build project

```Bash
cmake --build build
```

### Run Application (Main)

```Bash
./build/app
```

### Run Unit Tests

```Bash
cd build
ctest --output-on-failure
```

### Alternative (Manual Compile - Without CMake)

If you want to compile manually:

```Bash
g++ -std=c++17 -Iinclude src/sourcecode.cpp -o app
./app
````

# Adding a New Conversion Type

To add a new string conversion type:

1. **Create a new conversion class** in `include/` and `src/` following the `IStringConversion` interface.  
   **Example:** `ReverseCaseConversion.hpp` / `ReverseCaseConversion.cpp`.

2. **Update the `StringConversionFactory`** to include the new class:

```cpp
#include "ReverseCaseConversion.hpp"

case ConversionType::Reverse:
    return std::make_unique<ReverseCaseConversion>();
```
3. Update ProcessString.cpp to map a choice (e.g., 7) to the new ConversionType.
4. Modify CMakeLists.txt to include the new source files:
```
add_executable(StringConversionApp
    src/main.cpp
    src/LowerCaseConversion.cpp
    src/UpperCaseConversion.cpp
    src/CapitalizeWordsConversion.cpp
    src/SentenceCaseConversion.cpp
    src/ToggleCaseConversion.cpp
    src/AlternatingCaseConversion.cpp
    src/ReverseCaseConversion.cpp  # <-- New file
    src/StringConversionFactory.cpp
    src/ProcessString.cpp
)

target_include_directories(StringConversionApp PRIVATE include)
```

5. Rebuild the project using CMake:
```
cmake --build build
./build/StringConversionApp
```
6. Optionally, add unit tests in tests/StringConversionTests.cpp to verify the new conversion logic.
