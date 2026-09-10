#!/bin/bash

# Remove executables generated from C++ source files.
# Keeps .cpp, .md, .sh and other source/documentation files.

set -e

echo "Cleaning generated C++ executables..."
echo

find . -type f -name "*.cpp" -exec sh -c '
    for source_file do
        executable="${source_file%.cpp}"

        if [ -f "$executable" ] && [ -x "$executable" ]; then
            echo "Removing: $executable"
            rm "$executable"
        fi
    done
' sh {} +

echo
echo "Cleanup completed."