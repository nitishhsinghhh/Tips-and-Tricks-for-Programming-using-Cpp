#include <iostream>
#include "ProcessString.hpp"

int main() {
    std::string input;
    std::cout << "Enter string: ";
    std::getline(std::cin, input);

    std::cout << "1: Lower, 2: Upper, 3: Sentence, 4: Capitalize, 5: Toggle\n";

    int choice;
    std::cin >> choice;

    std::string result = processString(input, choice);

    std::cout << "Result: " << result << std::endl;

    return 0;
}