# STL Containers - Build System

This project provides a demonstration of how to build and run STL Containers in C++ using a local development setup. The source code and build scripts are located in the following directory on the user's machine:

```
C:/Users/UN/Interview_CPp/CppBasics
```

To build the project, use the following command in PowerShell:

```bash
C:\msys64\mingw64\bin\mingw32-make.exe all
```


This command initializes the build process, compiles the source files, and generates the executable in the `build` directory.


### Output:

```
Created build directory: build
============================================
      STL Containers - Build System
============================================
```

---

## 🧰 Compiler Details

- **Compiler Used:** MSYS2 MinGW-w64 g++
- **Compiler Path:** `C:/msys64/mingw64/bin/g++.exe`
- **Compile Flags:** `-std=c++17 -Wall -Wextra -O2`
- **Target Executable:** `build/stl_containers.exe`

---

## 🛠️ Compilation Steps

1. **Compile `stl_main.cpp`**
   ```bash
   g++ -std=c++17 -Wall -Wextra -O2 -I. -c stl_main.cpp -o build/stl_main.o
   ```

2. **Compile `STL_Containers.cpp`**
   ```bash
   g++ -std=c++17 -Wall -Wextra -O2 -I. -c STL_Containers.cpp -o build/12_STL_Containers.o
   ```

3. **Link Object Files**
   ```bash
   g++ build/stl_main.o build/12_STL_Containers.o -o build/stl_containers.exe
   ```

---

## Ways to Execute the Build

You can run the compiled executable in several ways depending on your workflow and environment:

### 1. Direct Execution (Simplest)
Run the executable directly from the root project directory:
```bash
.\build\stl_containers.exe
```

### 2. Using Makefile Run Target (Recommended)
Use the `run` target defined in the Makefile:
```bash
C:\msys64\mingw64\bin\mingw32-make.exe run
```

### 3. Change to Build Directory
Navigate to the build directory and run the executable:
```bash
cd build
.\stl_containers.exe
cd ..
```

### 4. Full Path Execution
Run the executable using its full path:
```bash
C:\Users\[UN]\Interview_CPp\CppBasics\build\stl_containers.exe
```

### 5. PowerShell Alternative Syntax
Use PowerShell's call operator to run the executable:
```powershell
& ".\build\stl_containers.exe"
```

