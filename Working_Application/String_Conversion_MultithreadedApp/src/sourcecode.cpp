#include <iostream>
#include <vector>
#include "UpperCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "MultiThreadManager.hpp"

int main() {
    UpperCaseConversion upperConverter;
    ToggleCaseConversion toggleConverter;

    std::vector<std::string> inputs = {"hello", "world", "multi-threaded"};

    std::cout << "=== UpperCase ===" << std::endl;
    MultiThreadManager::processStrings(upperConverter, inputs);

    std::cout << "=== ToggleCase ===" << std::endl;
    MultiThreadManager::processStrings(toggleConverter, inputs);

    return 0;
}