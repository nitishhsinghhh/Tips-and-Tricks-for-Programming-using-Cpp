#include "MultiThreadManager.hpp"
#include <thread>
#include <algorithm>

std::vector<std::string> MultiThreadManager::processStrings(
    const IStringConversion& converter,
    const std::vector<std::string>& inputs,
    int numThreads) {
        
    int total = inputs.size();

    // Edge case
    if (total == 0) 
        return {};

    // Avoid useless threads
    numThreads = std::min(numThreads, total);
    numThreads = std::max(1, numThreads);

    std::vector<std::string> results(total);  
    std::vector<std::thread> threads;

    int chunkSize = (total + numThreads - 1) / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = std::min(start + chunkSize, total);

        if (start >= total) 
            break;

        threads.emplace_back([&converter, &inputs, &results, start, end]() {
            for (int j = start; j < end; ++j) {
                results[j] = converter.convert(inputs[j]);  
            }
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    return results; 
}