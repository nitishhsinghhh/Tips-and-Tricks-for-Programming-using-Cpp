#!/bin/bash

# Compile and run all Binary Search examples.
#
# Usage:
#   ./run_all.sh

set -e

CXX="c++"
CXXFLAGS="-std=c++26 -Wall -Wextra -Wpedantic"

echo "========================================"
echo " Binary Search Examples"
echo "========================================"
echo

for source_file in *.cpp; do
    executable="${source_file%.cpp}"

    echo "========================================"
    echo "BUILD: ${source_file}"
    echo "========================================"

    $CXX $CXXFLAGS "$source_file" -o "$executable"

    echo
    echo "RUN: ./${executable}"
    echo "----------------------------------------"

    "./$executable"

    echo
done

echo "========================================"
echo " All examples compiled and executed"
echo " successfully."
echo "========================================"