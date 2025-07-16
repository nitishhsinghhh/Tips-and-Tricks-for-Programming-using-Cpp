
# Character Comparison Using ASCII in C++

## 🧠 Concept

In C++, characters are internally represented by their **ASCII values**. This means you can compare characters using relational operators (`<`, `>`, `==`, etc.) just like numbers.

For example:
- `'A'` has an ASCII value of **65**
- `'a'` has an ASCII value of **97**

So, `'A' < 'a'` evaluates to `true`.

This is useful in:
- **Sorting algorithms**
- **Lexicographical comparisons**
- **Case-sensitive checks**
- **Custom string comparison logic**

---

## ✅ Example Program: Compare Two Characters

```cpp
/**
 * @file CharAsciiCompareSOLID.cpp
 * @brief Compares two characters based on ASCII values using SOLID principles.
 * @author 
 * Nitish Singh
 */

#include <iostream>
#include <string>

/**
 * @interface IComparator
 * @brief Interface for comparing two characters.
 */
class IComparator {
public:
    virtual void compare(char a, char b) = 0;
    virtual ~IComparator() = default;
};

/**
 * @interface IPrinter
 * @brief Interface for printing ASCII values and comparison results.
 */
class IPrinter {
public:
    virtual void printAscii(char ch) = 0;
    virtual void printComparison(char a, char b) = 0;
    virtual ~IPrinter() = default;
};

/**
 * @class AsciiPrinter
 * @brief Prints ASCII values and comparison results.
 */
class AsciiPrinter : public IPrinter {
public:
    void printAscii(char ch) override {
        std::cout << "ASCII of '" << ch << "' is " << static_cast<int>(ch) << std::endl;
    }

    void printComparison(char a, char b) override {
        if (a == b)
            std::cout << "Both characters are equal.\n";
        else if (a < b)
            std::cout << a << " comes before " << b << " in ASCII order.\n";
        else
            std::cout << b << " comes before " << a << " in ASCII order.\n";
    }
};

/**
 * @class AsciiComparator
 * @brief Compares two characters and delegates printing.
 */
class AsciiComparator : public IComparator {
private:
    IPrinter& printer;

public:
    /**
     * @brief Constructor with dependency injection.
     * @param p Reference to a printer object.
     */
    AsciiComparator(IPrinter& p) : printer(p) {}

    void compare(char a, char b) override {
        printer.printAscii(a);
        printer.printAscii(b);
        printer.printComparison(a, b);
    }
};

/**
 * @class CharInput
 * @brief Handles user input of characters.
 */
class CharInput {
public:
    /**
     * @brief Prompts user for a character.
     * @param label Label to display before input.
     * @return The character entered by the user.
     */
    char getChar(const std::string& label) {
        char ch;
        std::cout << "Enter " << label << " character: ";
        std::cin >> ch;
        return ch;
    }
};

/**
 * @brief Main function to run the character comparison.
 * @return int Exit status.
 */
int main() {
    CharInput input;
    char ch1 = input.getChar("first");
    char ch2 = input.getChar("second");

    AsciiPrinter printer;
    AsciiComparator comparator(printer);
    comparator.compare(ch1, ch2);

    return 0;
}

```
