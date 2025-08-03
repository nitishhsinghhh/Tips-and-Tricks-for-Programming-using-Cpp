@echo off
setlocal enabledelayedexpansion

echo ============================================
echo       STL Containers - Build Script
echo ============================================
echo.

REM Set default compiler (try to find the best available)
set COMPILER_FOUND=0
set CXX=
set COMPILE_FLAGS=-std=c++17 -Wall -Wextra -O2

REM Try to find MSYS2/MinGW-w64 g++
if exist "C:\msys64\mingw64\bin\g++.exe" (
    set CXX=C:\msys64\mingw64\bin\g++.exe
    set COMPILER_FOUND=1
    echo Found MSYS2 MinGW-w64 g++ compiler
)

REM Try to find MinGW g++
if !COMPILER_FOUND!==0 (
    where g++ >nul 2>&1
    if !errorlevel!==0 (
        set CXX=g++
        set COMPILER_FOUND=1
        echo ✓ Found MinGW g++ compiler in PATH
    )
)

REM Try to find clang++
if !COMPILER_FOUND!==0 (
    where clang++ >nul 2>&1
    if !errorlevel!==0 (
        set CXX=clang++
        set COMPILER_FOUND=1
        echo ✓ Found Clang++ compiler in PATH
    )
)

REM Check if any compiler was found
if !COMPILER_FOUND!==0 (
    echo ERROR: No suitable C++ compiler found!
    echo.
    echo Please install one of the following:
    echo   - MSYS2 with MinGW-w64: https://www.msys2.org/
    echo   - MinGW-w64: https://www.mingw-w64.org/
    echo   - Clang: https://clang.llvm.org/
    echo.
    pause
    exit /b 1
)

echo Using compiler: !CXX!
echo Compile flags: !COMPILE_FLAGS!
echo.

REM Create build directory if it doesn't exist
if not exist "build" (
    mkdir build
    echo Created build directory
)

REM Source files (only STL related)
set SOURCES=stl_main.cpp 12_STL_Containers.cpp

REM Target executable
set TARGET=build\stl_containers.exe

echo Compiling STL Containers Demo...
echo.

REM Show which files are being compiled
echo Source files:
for %%f in (!SOURCES!) do (
    if exist "%%f" (
        echo   ✓ %%f
    ) else (
        echo   %%f ^(missing^)
        set MISSING_FILES=1
    )
)

REM Check if all files exist
if defined MISSING_FILES (
    echo.
    echo ERROR: Some source files are missing
    pause
    exit /b 1
)

echo.
echo Building executable...

REM Compile
"!CXX!" !COMPILE_FLAGS! !SOURCES! -o !TARGET!

if !errorlevel!==0 (
    echo.
    echo BUILD SUCCESSFUL!
    echo Executable created: !TARGET!
    echo.
    echo Running STL Containers Demo...
    echo ============================================
    echo.
    
    REM Run the program
    !TARGET!
    
    echo.
    echo ============================================
    echo STL Containers Demo completed!
) else (
    echo.
    echo BUILD FAILED!
    echo Check the error messages above.
)

echo.
pause 
