#include <iostream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <cassert>
#include <map>

// Interface
class IConverter {
public:
    virtual std::string convert(int decimal) = 0;
    virtual ~IConverter() = default;
};

// Implementation
class NumberConverter : public IConverter {
public:
    std::string convert(int decimal) override {
        std::stringstream ss;
        ss << std::setw(7) << decimal << " | "
           << std::setw(7) << std::oct << decimal << " | "
           << std::setw(7) << std::hex << std::uppercase << decimal << " | ";

        if (decimal < 32 || decimal == 127) {
            ss << std::setw(7) << controlCharName(decimal);
        } else {
            ss << std::setw(7) << static_cast<char>(decimal);
        }

        ss << std::dec << std::nouppercase; // reset formatting
        return ss.str();
    }

    static std::string controlCharName(int code) {
        static std::map<int, std::string> names = {
            {0,"NUL"},{1,"SOH"},{2,"STX"},{3,"ETX"},{4,"EOT"},{5,"ENQ"},{6,"ACK"},{7,"BEL"},
            {8,"BS"},{9,"TAB"},{10,"LF"},{11,"VT"},{12,"FF"},{13,"CR"},{14,"SO"},{15,"SI"},
            {16,"DLE"},{17,"DC1"},{18,"DC2"},{19,"DC3"},{20,"DC4"},{21,"NAK"},{22,"SYN"},{23,"ETB"},
            {24,"CAN"},{25,"EM"},{26,"SUB"},{27,"ESC"},{28,"FS"},{29,"GS"},{30,"RS"},{31,"US"},
            {127,"DEL"}
        };
        return names[code];
    }
};

// Test class
class ConverterTest {
public:
    void runAsciiTest() {
        std::unique_ptr<IConverter> converter = std::make_unique<NumberConverter>();

        std::cout << std::setw(7) << "Dec" << " | "
                  << std::setw(7) << "Oct" << " | "
                  << std::setw(7) << "Hex" << " | "
                  << std::setw(7) << "Char" << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;

        for (int i = 0; i <= 127; i++) {
            std::string result = converter->convert(i);
            std::cout << result << std::endl;

            // Build exact expected string using same logic
            std::stringstream expected;
            expected << std::setw(7) << i << " | "
                     << std::setw(7) << std::oct << i << " | "
                     << std::setw(7) << std::hex << std::uppercase << i << " | ";
            if (i < 32 || i == 127) {
                expected << std::setw(7) << NumberConverter::controlCharName(i);
            } else {
                expected << std::setw(7) << static_cast<char>(i);
            }
            expected << std::dec << std::nouppercase;

            assert(result == expected.str());
        }

        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "All ASCII conversion tests passed successfully!" << std::endl;
    }
};

int main() {
    ConverterTest test;
    test.runAsciiTest();
    return 0;
}
