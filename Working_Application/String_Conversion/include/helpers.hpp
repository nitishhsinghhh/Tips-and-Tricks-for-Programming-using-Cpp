#ifndef PROCESS_STRING_HPP
#define PROCESS_STRING_HPP

#include "Client.hpp"
#include "StringConversionFactory.hpp"

inline std::string processString(const std::string& input, int choice) {
    Client client;

    ConversionType type = ConversionType::Lower;

    switch (choice) {
        case 1: type = ConversionType::Lower; break;
        case 2: type = ConversionType::Upper; break;
        case 3: type = ConversionType::Sentence; break;
        case 4: type = ConversionType::Capitalize; break;
        case 5: type = ConversionType::Toggle; break;
    }

    client.setStrategy(StringConversionFactory::create(type));
    return client.execute(input);
}

#endif // PROCESS_STRING_HPP