#include "ProcessString.hpp"
#include "Client.hpp"
#include "StringConversionFactory.hpp"

std::string processString(const std::string& input, int choice) {
    Client client;

    ConversionType type;

    switch (choice) {
        case 1: type = ConversionType::Lower; break;
        case 2: type = ConversionType::Upper; break;
        case 3: type = ConversionType::Capitalize; break;  // Corrected
        case 4: type = ConversionType::Sentence; break;     // Corrected
        case 5: type = ConversionType::Toggle; break;
        case 6: type = ConversionType::Alternating; break;      // Already correct
        case 7: type = ConversionType::Reverse; break;          // Added case for Reverse
        default: return input;                                   // fallback
    }

    client.setStrategy(StringConversionFactory::create(type));
    return client.execute(input);
}