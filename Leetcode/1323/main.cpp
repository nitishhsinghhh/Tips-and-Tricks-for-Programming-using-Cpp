#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

enum class PositionMode { ANY, EVEN_INDEX, ODD_INDEX, LAST_N };

struct TransformResult {
    std::string original;
    std::string transformed;
    int changesMade;
};

class DigitTransformer {
public:
    // Transform using single digit replacement
    TransformResult transformDigits(int num, char fromDigit, char toDigit,
                                    int maxChanges = -1, int base = 10,
                                    PositionMode mode = PositionMode::ANY,
                                    int lastN = 0) {
        std::string numberStr = std::to_string(std::abs(num));
        std::string originalStr = numberStr;
        int changes = 0;

        int len = numberStr.size();
        for (int i = 0; i < len; ++i) {
            if (!isValidDigit(numberStr[i], base))
                continue;

            if (mode == PositionMode::EVEN_INDEX && i % 2 != 0)
                continue;
            if (mode == PositionMode::ODD_INDEX && i % 2 == 0)
                continue;
            if (mode == PositionMode::LAST_N && i < len - lastN)
                continue;

            if (numberStr[i] == fromDigit) {
                numberStr[i] = toDigit;
                ++changes;
                if (maxChanges != -1 && changes == maxChanges)
                    break;
            }
        }

        if (num < 0)
            numberStr = "-" + numberStr;
        return {(num < 0 ? "-" + originalStr : originalStr), numberStr,
                changes};
    }

    // Transform using a digit map
    TransformResult
    transformWithMap(const std::string& input,
                     const std::unordered_map<char, char>& digitMap,
                     int maxChanges = -1, PositionMode mode = PositionMode::ANY,
                     int lastN = 0) {
        std::string result = input;
        int changes = 0;
        int len = result.size();

        for (int i = 0; i < len; ++i) {
            char& ch = result[i];
            if (!std::isdigit(ch))
                continue;

            if (mode == PositionMode::EVEN_INDEX && i % 2 != 0)
                continue;
            if (mode == PositionMode::ODD_INDEX && i % 2 == 0)
                continue;
            if (mode == PositionMode::LAST_N && i < len - lastN)
                continue;

            auto it = digitMap.find(ch);
            if (it != digitMap.end()) {
                ch = it->second;
                ++changes;
                if (maxChanges != -1 && changes == maxChanges)
                    break;
            }
        }

        return {input, result, changes};
    }

private:
    bool isValidDigit(char ch, int base) {
        if (base <= 10)
            return ch >= '0' && ch < '0' + base;
        return std::isdigit(ch) ||
               (std::tolower(ch) >= 'a' && std::tolower(ch) < 'a' + base - 10);
    }
};
int main() {
    DigitTransformer dt;

    // Basic transformation
    auto res1 = dt.transformDigits(696969, '6', '9', 2);
    assert(res1.transformed == "999969");

    // Transform all occurrences
    auto res2 = dt.transformDigits(696969, '6', '9', -1);
    assert(res2.transformed == "999999");

    // Negative number
    auto res3 = dt.transformDigits(-969696, '9', '6', 3);
    assert(res3.transformed == "-666666");

    // Position-based (only last 2 digits)
    auto res4 =
        dt.transformDigits(696969, '6', '9', -1, 10, PositionMode::LAST_N, 2);
    assert(res4.transformed == "696999");

    // Bulk map transformation
    std::unordered_map<char, char> digitMap = {{'6', '9'}, {'9', '6'}};
    auto res5 = dt.transformWithMap("696969", digitMap, -1);
    assert(res5.transformed == "969696");

    std::cout << "All tests cases passed successfully!" << std::endl;
    return 0;
}