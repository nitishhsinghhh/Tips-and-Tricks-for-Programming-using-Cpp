#include "MultiThreadManager.hpp"
#include <iostream>

void MultiThreadManager::processStrings(const IStringConversion& converter, const std::vector<std::string>& inputs) {
    std::vector<std::thread> threads;

    for (const auto& str : inputs) {
        threads.emplace_back([&converter, str]() {
            std::string result = converter.convert(str);
            std::cout << result << std::endl;
        });
    }

    for (auto& t : threads) t.join();
}