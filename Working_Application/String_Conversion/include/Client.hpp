#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <memory>
#include <string>
#include "IStringConversion.hpp"

class Client {
private:
    std::unique_ptr<IStringConversion> strategy;

public:
    void setStrategy(std::unique_ptr<IStringConversion> s) {
        strategy = std::move(s);
    }

    std::string execute(const std::string& input) const {
        if (!strategy) return input;
        return strategy->convert(input);
    }
};

#endif // CLIENT_HPP