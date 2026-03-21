// GCC 13.1: C++23
#include <iostream>
#include <iomanip>
#include <map>

std::string controlCharName(int code) {
    static std::map<int, std::string> names = {
        {0,"NUL"},{1,"SOH"},{2,"STX"},{3,"ETX"},{4,"EOT"},{5,"ENQ"},{6,"ACK"},{7,"BEL"},
        {8,"BS"},{9,"TAB"},{10,"LF"},{11,"VT"},{12,"FF"},{13,"CR"},{14,"SO"},{15,"SI"},
        {16,"DLE"},{17,"DC1"},{18,"DC2"},{19,"DC3"},{20,"DC4"},{21,"NAK"},{22,"SYN"},{23,"ETB"},
        {24,"CAN"},{25,"EM"},{26,"SUB"},{27,"ESC"},{28,"FS"},{29,"GS"},{30,"RS"},{31,"US"},
        {127,"DEL"}
    };
    return names[code];
}

int main() {
    std::cout << "ASCII Chart [0..127]\n";
    std::cout << std::setw(7) << "Dec" << " | "
              << std::setw(7) << "Oct" << " | "
              << std::setw(7) << "Hex" << " | "
              << std::setw(7) << "Char" << "\n";
    std::cout << "------------------------------------------------------\n";

    for (int i = 0; i <= 127; ++i) {
        std::cout << std::setw(7) << i << " | "
                  << std::setw(7) << std::oct << i << " | "
                  << std::setw(7) << std::hex << std::uppercase << i << " | ";

        if (i < 32 || i == 127) {
            std::cout << std::setw(7) << controlCharName(i);
        } else {
            std::cout << std::setw(7) << static_cast<char>(i);
        }

        std::cout << std::dec << std::nouppercase << "\n"; // reset formatting
    }

    std::cout << "------------------------------------------------------\n";
    std::cout << "Chart complete.\n";
}
