#!/bin/bash

# Compile and run all C++ Dynamic Programming examples.

set -e

CXX="c++"
CXXFLAGS="-std=c++26 -Wall -Wextra -Wpedantic"

echo "========================================"
echo " Dynamic Programming Examples"
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

    if [[ "$executable" == "fibonacci" || "$executable" == "climbing_stairs" ]]; then
        printf "5\n" | "./$executable"
    else
        "./$executable"
    fi

    echo
done

echo "========================================"
echo " All examples compiled and executed"
echo " successfully."
echo "========================================"
