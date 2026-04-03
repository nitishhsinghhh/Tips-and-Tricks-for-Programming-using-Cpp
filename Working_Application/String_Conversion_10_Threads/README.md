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
│ 
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
```

## Build & Run Instructions (CMake)

### Step 1: Configure the Project

Generate build files using CMake:

```bash
cmake -S . -B build
```

---

### Step 2: Build the Project

```bash
cmake --build build
```

---

### Step 3: Run the Application

```bash
./build/app
```

---

### Step 4: Run Unit Tests

```bash
cd build
ctest --output-on-failure
```

---

## Notes

* Do **not** run `make` directly in the root directory.
* This project uses **CMake**, so build files are generated inside the `build/` folder.
* If needed, you can run `make` inside the `build/` directory after configuration:

```bash
cd build
make
```

---

## Clean Build

To rebuild from scratch:

```bash
rm -rf build
cmake -S . -B build
cmake --build build
```

---

## Troubleshooting

### Warning: `DOWNLOAD_EXTRACT_TIMESTAMP`

This is a CMake developer warning and does not affect execution. It can be safely ignored.

---

### Error: `No makefile found`

Make sure you have run:

```bash
cmake -S . -B build
```

before attempting to build.

---

## Example Output

```text
=== UpperCase (10 threads) ===
=== ToggleCase (10 threads) ===
```

This confirms the application is running successfully with multithreading.