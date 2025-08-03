# STL Containers - Makefile
# Comprehensive build system for STL demonstration project

# Project configuration
PROJECT_NAME = stl_containers
TARGET_DIR = build
TARGET = $(TARGET_DIR)/$(PROJECT_NAME).exe

# Source files (STL related only)
SOURCES = stl_main.cpp STL_Containers.cpp
OBJECTS = $(SOURCES:%.cpp=$(TARGET_DIR)/%.o)

# Compiler detection (priority order: MSYS2/MinGW-w64 > MinGW > Clang)
# Check for MSYS2/MinGW-w64 g++ first
ifneq ($(wildcard C:/msys64/mingw64/bin/g++.exe),)
    CXX = C:/msys64/mingw64/bin/g++.exe
    COMPILER_NAME = MSYS2 MinGW-w64 g++
else
    # Check for g++ in PATH
    ifeq ($(shell where g++ 2>nul),)
        # Check for clang++ in PATH
        ifeq ($(shell where clang++ 2>nul),)
            $(error No suitable C++ compiler found! Please install MSYS2/MinGW-w64, MinGW, or Clang)
        else
            CXX = clang++
            COMPILER_NAME = Clang++
        endif
    else
        CXX = g++
        COMPILER_NAME = MinGW g++
    endif
endif

# Compiler flags (matching .bat file settings)
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
LDFLAGS = 

# Include directories
INCLUDES = -I.

# Colors for output (Windows compatible)
COLOR_GREEN = 
COLOR_BLUE = 
COLOR_YELLOW = 
COLOR_RED = 
COLOR_RESET = 

# Default target
.PHONY: all
all: banner $(TARGET)

# Display build information
.PHONY: banner
banner:
	@echo ============================================
	@echo       STL Containers - Build System
	@echo ============================================
	@echo.
	@echo Using compiler: $(CXX)
	@echo Compiler: $(COMPILER_NAME)
	@echo Compile flags: $(CXXFLAGS)
	@echo Target: $(TARGET)
	@echo.

# Create build directory
$(TARGET_DIR):
	@if not exist "$(TARGET_DIR)" mkdir $(TARGET_DIR)
	@echo Created build directory: $(TARGET_DIR)

# Build the main executable
$(TARGET): $(TARGET_DIR) $(OBJECTS)
	@echo.
	@echo Building executable...
	@echo Linking: $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@
	@echo.
	@echo BUILD SUCCESSFUL!
	@echo Executable created: $(TARGET)

# Compile source files to object files
$(TARGET_DIR)/%.o: %.cpp | $(TARGET_DIR)
	@echo Compiling: $<
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Run the program
.PHONY: run
run: $(TARGET)
	@echo.
	@echo Running STL Containers Demo...
	@echo ============================================
	@echo.
	@$(TARGET)
	@echo.
	@echo ============================================
	@echo STL Containers Demo completed!

# Clean build artifacts
.PHONY: clean
clean:
	@echo Cleaning build artifacts...
	@if exist "$(TARGET_DIR)" rmdir /s /q $(TARGET_DIR)
	@echo Clean completed!

# Clean and rebuild
.PHONY: rebuild
rebuild: clean all

# Show help information
.PHONY: help
help:
	@echo STL Containers Build System - Available targets:
	@echo.
	@echo   all      - Build the project (default)
	@echo   run      - Build and run the STL demo
	@echo   clean    - Remove all build artifacts
	@echo   rebuild  - Clean and rebuild everything
	@echo   help     - Show this help message
	@echo   info     - Show detailed build information
	@echo.
	@echo Examples:
	@echo   make         # Build the project
	@echo   make run     # Build and run
	@echo   make clean   # Clean build files
	@echo   make rebuild # Clean and rebuild

# Show detailed build information
.PHONY: info
info:
	@echo ============================================
	@echo         Build Configuration Info
	@echo ============================================
	@echo Project: $(PROJECT_NAME)
	@echo Compiler: $(CXX) ($(COMPILER_NAME))
	@echo Flags: $(CXXFLAGS)
	@echo Sources: $(SOURCES)
	@echo Objects: $(OBJECTS)
	@echo Target: $(TARGET)
	@echo Build Dir: $(TARGET_DIR)
	@echo ============================================

# Debug build variant
.PHONY: debug
debug: CXXFLAGS = -std=c++17 -Wall -Wextra -g -DDEBUG -O0
debug: banner $(TARGET)
	@echo Debug build completed!

# Release build variant (optimized)
.PHONY: release
release: CXXFLAGS = -std=c++17 -Wall -Wextra -O3 -DNDEBUG -march=native
release: banner $(TARGET)
	@echo Release build completed!

# Check if all source files exist
.PHONY: check-sources
check-sources:
	@echo Checking source files...
	@for %%f in ($(SOURCES)) do ( \
		if exist "%%f" ( \
			echo   ✓ %%f \
		) else ( \
			echo   ✗ %%f (missing) \
			exit /b 1 \
		) \
	)
	@echo All source files found!

# Install/copy to a different location (optional)
INSTALL_DIR = ../bin
.PHONY: install
install: $(TARGET)
	@if not exist "$(INSTALL_DIR)" mkdir $(INSTALL_DIR)
	@copy "$(TARGET)" "$(INSTALL_DIR)\"
	@echo Installed to: $(INSTALL_DIR)/$(PROJECT_NAME).exe

# Dependency tracking (automatic header dependencies)
-include $(OBJECTS:.o=.d)

$(TARGET_DIR)/%.d: %.cpp | $(TARGET_DIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MM -MT $(@:.d=.o) $< > $@

# Mark targets that don't create files
.PHONY: all banner run clean rebuild help info debug release check-sources install 
