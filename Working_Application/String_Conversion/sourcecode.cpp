#include <iostream>
#include "Client.hpp"
#include "StringConversionFactory.hpp"

int main() {
    Client client;

    std::string input;
    std::cout << "Enter string: ";
    std::getline(std::cin, input);

    std::cout << "1: Lower, 2: Upper, 3: Sentence, 4: Capitalize, 5: Toggle\n";

    int choice;
    std::cin >> choice;

    ConversionType type = ConversionType::Lower;

    switch (choice) {
        case 1: type = ConversionType::Lower; break;
        case 2: type = ConversionType::Upper; break;
        case 3: type = ConversionType::Sentence; break;
        case 4: type = ConversionType::Capitalize; break;
        case 5: type = ConversionType::Toggle; break;
    }

    client.setStrategy(StringConversionFactory::create(type));

    std::cout << "Result: " << client.execute(input) << std::endl;

    return 0;
}