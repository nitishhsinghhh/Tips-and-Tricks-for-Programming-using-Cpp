// GCC 13.1: C++23
#include <iomanip>
#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::setw
using std::nouppercase;
using std::dec;

string controlCharName(int code) {
    static map<int, string> names = {
        {0, "NUL"},  {1, "SOH"},  {2, "STX"},  {3, "ETX"},  {4, "EOT"},
        {5, "ENQ"},  {6, "ACK"},  {7, "BEL"},  {8, "BS"},   {9, "TAB"},
        {10, "LF"},  {11, "VT"},  {12, "FF"},  {13, "CR"},  {14, "SO"},
        {15, "SI"},  {16, "DLE"}, {17, "DC1"}, {18, "DC2"}, {19, "DC3"},
        {20, "DC4"}, {21, "NAK"}, {22, "SYN"}, {23, "ETB"}, {24, "CAN"},
        {25, "EM"},  {26, "SUB"}, {27, "ESC"}, {28, "FS"},  {29, "GS"},
        {30, "RS"},  {31, "US"},  {127, "DEL"}};
    return names[code];
}

int main() {
    cout << "ASCII Chart [0..127]\n";
    cout << setw(7) << "Dec" << " | " << setw(7) << "Oct" << " | "
         << setw(7) << "Hex" << " | " << setw(7) << "Char" << "\n";
    cout << "------------------------------------------------------\n";

    for (int i = 0; i <= 127; ++i) {
        cout << setw(7) << i << " | " << setw(7) << std::oct << i
             << " | " << setw(7) << std::hex << std::uppercase << i
             << " | ";

        if (i < 32 || i == 127) {
            cout << setw(7) << controlCharName(i);
        } else {
            cout << setw(7) << static_cast<char>(i);
        }

        cout << dec << nouppercase << "\n"; // reset formatting
    }

    cout << "------------------------------------------------------\n";
    cout << "Chart complete.\n";
}
