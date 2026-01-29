# [ASCII Chart](https://cppreference.com/w/cpp/language/ascii.html)

The following chart contains all 128 ASCII decimal (dec), octal (oct), hexadecimal (hex) and character (ch) codes.

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/f257abee-7cc9-4038-b2ab-61c59c202745)

## What the Chart Shows
The chart is organized into four columns per row, and each column contains:

### 1. Decimal (`dec`)
- **Base 10** number system (0–9)
- This is the standard numbering system used in everyday life.
- Example: `65` in decimal represents the character `'A'`.

### 2. Octal (`oct`)
- **Base 8** number system (0–7)
- Commonly used in older computing systems and Unix file permissions.
- Example: `101` in octal is equal to `65` in decimal, which is `'A'` in ASCII.

### 3. Hexadecimal (`hex`)
- **Base 16** number system (0–9 and A–F)
- Widely used in programming and debugging due to its compact binary representation.
- Example: `41` in hexadecimal is equal to `65` in decimal, which is `'A'` in ASCII.

Conversion Example

| Format      | Value | ASCII Character |
|-------------|-------|-----------------|
| Decimal     | 65    | `'A'`           |
| Octal       | 101   | `'A'`           |
| Hexadecimal | 41    | `'A'`           |

### Why It Matters?
Understanding these formats is essential for:
- Debugging memory and binary data
- Working with low-level system code
- Encoding and decoding data
- Interpreting ASCII tables and character sets

### ch: Character (symbol or control code)
Each row shows four such entries, so you can see all 128 ASCII codes from 0 to 127.

## Types of Characters in ASCII

###  Control Characters (0–31 and 127)
These are non-printable characters used for control in text streams:

- 0 (NUL): Null
- 7 (BEL): Bell (triggers a beep)
- 8 (BS): Backspace
- 9 (HT): Horizontal Tab
- 10 (LF): Line Feed (newline)
- 13 (CR): Carriage Return
- 27 (ESC): Escape
- 127 (DEL): Delete
These are useful in low-level programming, terminal control, and communication protocols.

### Printable Characters (32–126)
These include:

- Space (32)
- Digits: 48–57 → '0' to '9'
- Uppercase letters: 65–90 → 'A' to 'Z'
- Lowercase letters: 97–122 → 'a' to 'z'
- Symbols: 33–47, 58–64, 91–96, 123–126 → like !, @, [, }, etc.

```CPP
// GCC 13.1: C++ 23
#include <iostream>
/**
 * @desc
 * This program prints all printable ASCII characters in the range [32..126].
 * It displays them in a formatted way, printing a newline after every 32 characters.
 *
 * @result
 * Outputs the printable ASCII characters from space (' ') to tilde ('~') to the console.
 */
int main() {
    std::cout << "Printable ASCII [32..126]:\n";

    // Loop through characters from ASCII 32 (' ') to 126 ('~')
    for (char c{ ' ' }; c <= '~'; ++c)
        // Print character followed by a space or newline every 32 characters
        std::cout << c << ((c + 1) % 32 ? ' ' : '\n');
    std::cout << '\n';
}
```
```
Output: 
Printable ASCII [32..126]:
  ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ?
@ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _
` a b c d e f g h i j k l m n o p q r s t u v w x y z { | } ~
```

# ASCII Chart Generator in C++
This program prints the complete ASCII chart for codes [0..127], showing: 
- Decimal (dec)
- Octal (oct)
- Hexadecimal (hex)
- Character (ch) or control name

## Version 1: Basic Printer
This version simply prints the ASCII chart for codes [0–127]. It’s straightforward and ideal for beginners.

```Cpp
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
```
## Version 2: Tested Printer
This version adds an interface, implementation, and test class. It uses assert to verify that each row matches the expected output. This is more advanced and demonstrates OOP + unit testing concepts.
```cpp
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
```
