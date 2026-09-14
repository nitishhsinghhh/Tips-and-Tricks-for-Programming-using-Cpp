/**
 * @file time_based_key_value_store.cpp
 * @author Nitish Singh
 * @brief Demonstrates time-based key-value lookup using upper_bound.
 */

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

/**
 * @class TimeMap
 * @brief Stores values associated with keys and timestamps.
 */
class TimeMap {
private:
    std::unordered_map<
        std::string,
        std::map<int, std::string>
    > data;

public:
    /**
     * @brief Stores a value for a key at a timestamp.
     *
     * @param key Key.
     * @param value Value.
     * @param timestamp Timestamp.
     */
    void set(const std::string& key,
            const std::string& value,
            int timestamp) {
        data[key][timestamp] = value;
    }

    /**
     * @brief Retrieves the most recent value at or before timestamp.
     *
     * @param key Key.
     * @param timestamp Maximum timestamp.
     * @return std::string Matching value or empty string.
     */
    std::string get(const std::string& key, int timestamp) const {
        const auto keyIterator = data.find(key);

        if (keyIterator == data.end()) {
            return "";
        }

        const auto& timestamps = keyIterator->second;
        const auto iterator = timestamps.upper_bound(timestamp);

        if (iterator == timestamps.begin()) {
            return "";
        }

        return std::prev(iterator)->second;
    }
};

/**
 * @brief Demonstrates time-based lookup.
 *
 * @return int Exit status.
 */
int main() {
    TimeMap timeMap;

    timeMap.set("foo", "bar", 1);
    timeMap.set("foo", "bar2", 4);

    std::cout << "Value at timestamp 1: "
              << timeMap.get("foo", 1) << '\n';

    std::cout << "Value at timestamp 3: "
              << timeMap.get("foo", 3) << '\n';

    std::cout << "Value at timestamp 4: "
              << timeMap.get("foo", 4) << '\n';

    return 0;
}