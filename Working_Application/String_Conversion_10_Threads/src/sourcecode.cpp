#include <iostream>
#include <vector>
#include <string>
#include "UpperCaseConversion.hpp"
#include "ToggleCaseConversion.hpp"
#include "MultiThreadManager.hpp"

int main() {
    UpperCaseConversion upperConverter;
    ToggleCaseConversion toggleConverter;

    // Generate 100 sample inputs
    std::vector<std::string> inputs;
    for (int i = 0; i < 10; ++i) {
        inputs.push_back("string_" + std::to_string(i));
    }

    std::cout << "=== UpperCase (10 threads) ===" << std::endl;
    MultiThreadManager::processStrings(upperConverter, inputs, /*numThreads=*/100);

    std::cout << "=== ToggleCase (10 threads) ===" << std::endl;
    MultiThreadManager::processStrings(toggleConverter, inputs, /*numThreads=*/100);

    return 0;
}
