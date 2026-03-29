#include "Client.hpp"

void Client::setStrategy(std::unique_ptr<IStringConversion> s) {
    strategy = std::move(s);
}

std::string Client::execute(const std::string& input) const {
    if (!strategy) return input;
    return strategy->convert(input);
}