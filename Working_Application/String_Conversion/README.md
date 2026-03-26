# Refactored Design (SOLID)

This project demonstrates a clean C++ design using SOLID principles and modern C++ practices.

| Principle | Fix |
| --- | --- |
| SRP (Single Responsibility Principle) | Separate conversion logic, factory creation, and client usage into different classes |
| OCP (Open/Closed Principle) | Add new conversion classes without modifying existing switch/conditional logic |
| DIP (Dependency Inversion Principle) | Depend on abstractions (interfaces/abstract classes) instead of concrete implementations |
| RAII (Resource Acquisition Is Initialization) | Use `std::unique_ptr` for automatic memory management and resource safety |

## File Structure

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
