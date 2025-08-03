# STL Containers - Build System

This project provides a demonstration of how to build and run STL Containers in C++ using a local development setup. The source code and build scripts are located in the following directory on the user's machine:

```
C:/Users/[UN]/Interview_CPp/CppBasics
```

To build the project, use the following command in PowerShell:

```bash
C:\msys64\mingw64\bin\mingw32-make.exe all
```
<img width="1083" height="932" alt="{ACB36D78-5BEC-4A6A-A7F4-595C52336916}" src="https://github.com/user-attachments/assets/25eb646d-eb6c-480d-939f-e0db4ea1d34f" />



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


# All Available Makefile Commands

The Makefile provides multiple targets for different development processes:

## Basic Build Commands

**Build the project (default):**
```bash
C:\msys64\mingw64\bin\mingw32-make.exe all
# OR simply:
C:\msys64\mingw64\bin\mingw32-make.exe
```

**Build and run immediately:**
```bash
C:\msys64\mingw64\bin\mingw32-make.exe run
```

## Clean and Rebuild Commands

**Clean all build artifacts:**
```bash
C:\msys64\mingw64\bin\mingw32-make.exe clean
```
*Removes the entire `build/` directory and all compiled files*

**Clean and rebuild everything:**
```bash
C:\msys64\mingw64\bin\mingw32-make.exe rebuild
```
*Equivalent to running `clean` followed by `all`*

## Build Variants

**Debug build (with debugging symbols):**
```bash
C:\msys64\mingw64\bin\mingw32-make.exe debug
```
*Compiler flags: `-std=c++17 -Wall -Wextra -g -DDEBUG -O0`*
*Best for debugging with GDB or IDE debuggers*

**Release build (optimized):**
```bash
C:\msys64\mingw64\bin\mingw32-make.exe release
```
*Compiler flags: `-std=c++17 -Wall -Wextra -O3 -DNDEBUG -march=native`*
*Best for production/performance testing*

## Information and Help Commands

**Show detailed build configuration:**
```bash
C:\msys64\mingw64\bin\mingw32-make.exe info
```
*Displays compiler, flags, source files, target, and build directory*

**Show all available targets:**
```bash
C:\msys64\mingw64\bin\mingw32-make.exe help
```
*Shows this help information with examples*

## Advanced Commands

**Check if source files exist:**
```bash
C:\msys64\mingw64\bin\mingw32-make.exe check-sources
```
*Validates that all required source files are present*

**Install to another directory:**
```bash
C:\msys64\mingw64\bin\mingw32-make.exe install
```
*Copies executable to `../bin/` directory*

## Command Examples with Expected Output

## Build Process
```bash
# Command:
C:\msys64\mingw64\bin\mingw32-make.exe all

# Expected Output:
============================================
      STL Containers - Build System
============================================

Using compiler: C:/msys64/mingw64/bin/g++.exe
Compiler: MSYS2 MinGW-w64 g++
Compile flags: -std=c++17 -Wall -Wextra -O2
Target: build/stl_containers.exe

Compiling: stl_main.cpp
Compiling: 12_STL_Containers.cpp
Building executable...
BUILD SUCCESSFUL!
Executable created: build/stl_containers.exe
```

## Clean Process
```bash
# Command:
C:\msys64\mingw64\bin\mingw32-make.exe clean

# Expected Output:
Cleaning build artifacts...
Clean completed!
```

## Debug Build
```bash
# Command:
C:\msys64\mingw64\bin\mingw32-make.exe debug

# Expected Output:
============================================
      STL Containers - Build System
============================================

Using compiler: C:/msys64/mingw64/bin/g++.exe
Compiler: MSYS2 MinGW-w64 g++
Compile flags: -std=c++17 -Wall -Wextra -g -DDEBUG -O0
Target: build/stl_containers.exe

[... compilation process ...]
Debug build completed!
```

## Configuration Info
```bash
# Command:
C:\msys64\mingw64\bin\mingw32-make.exe info

# Expected Output:
============================================
        Build Configuration Info
============================================
Project: stl_containers
Compiler: C:/msys64/mingw64/bin/g++.exe (MSYS2 MinGW-w64 g++)
Flags: -std=c++17 -Wall -Wextra -O2
Sources: stl_main.cpp 12_STL_Containers.cpp
Objects: build/stl_main.o build/12_STL_Containers.o
Target: build/stl_containers.exe
Build Dir: build
============================================
```

## Quick Reference Table

| Command | Purpose | When to Use |
|---------|---------|-------------|
| `all` | Standard build | Default development |
| `run` | Build and execute | Quick testing |
| `clean` | Remove build files | Fresh start needed |
| `rebuild` | Clean + build | After major changes |
| `debug` | Debug build | Debugging with GDB |
| `release` | Optimized build | Performance testing |
| `info` | Show configuration | Check build settings |
| `help` | Show all targets | Learn available options |
| `check-sources` | Validate files | Troubleshooting |
| `install` | Copy executable | Deploy to bin folder |

## Common Workflow Examples

**Development Workflow:**
```bash
# 1. Build and test
C:\msys64\mingw64\bin\mingw32-make.exe run

# 2. Make changes to code...

# 3. Rebuild and test
C:\msys64\mingw64\bin\mingw32-make.exe rebuild
```

**Debugging Workflow:**
```bash
# 1. Create debug build
C:\msys64\mingw64\bin\mingw32-make.exe debug

# 2. Run with debugger
gdb .\build\stl_containers.exe
```

**Release Workflow:**
```bash
# 1. Clean previous builds
C:\msys64\mingw64\bin\mingw32-make.exe clean

# 2. Create optimized build
C:\msys64\mingw64\bin\mingw32-make.exe release

# 3. Test performance
.\build\stl_containers.exe
```

