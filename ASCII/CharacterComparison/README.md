
# Character Comparison Using ASCII in C++

## Concept

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

## Compare Two Characters

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
# C++ Program: Case Check, Letter Match, and Alphabetical Order
```cpp
#include <iostream>

/**
 * @interface IValidator
 * @brief Interface for validating character input.
 */
class IValidator {
public:
    virtual bool isValid(char ch) const = 0;
    virtual ~IValidator() = default;
};

/**
 * @class AlphaValidator
 * @brief Validates if a character is an alphabetic letter (A-Z or a-z).
 */
class AlphaValidator : public IValidator {
public:
    bool isValid(char ch) const override {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }
};

/**
 * @interface IPrinter
 * @brief Interface for printing character information.
 */
class IPrinter {
public:
    virtual void printCase(char ch) const = 0;
    virtual void printMatch(bool match) const = 0;
    virtual void printOrder(char ch1, char ch2) const = 0;
    virtual void printError() const = 0;
    virtual ~IPrinter() = default;
};

/**
 * @class ConsolePrinter
 * @brief Prints character details and comparison results to the console.
 */
class ConsolePrinter : public IPrinter {
public:
    void printCase(char ch) const override {
        std::cout << "Character '" << ch << "' is "
                  << ((ch >= 'A' && ch <= 'Z') ? "uppercase" : "lowercase") << ".\n";
    }

    void printMatch(bool match) const override {
        if (match)
            std::cout << "Both characters represent the same letter (case-insensitive).\n";
        else
            std::cout << "The characters are different letters.\n";
    }

    void printOrder(char ch1, char ch2) const override {
        char lower1 = toLower(ch1);
        char lower2 = toLower(ch2);

        if (lower1 < lower2)
            std::cout << "'" << ch2 << "' comes after '" << ch1 << "' in the alphabet.\n";
        else
            std::cout << "'" << ch2 << "' comes before '" << ch1 << "' in the alphabet.\n";
    }

    void printError() const override {
        std::cout << "Both inputs must be alphabetic letters.\n";
    }

private:
    char toLower(char ch) const {
        return (ch >= 'A' && ch <= 'Z') ? (ch + 32) : ch;
    }
};

/**
 * @interface IComparer
 * @brief Interface for comparing two characters.
 */
class IComparer {
public:
    virtual void compare(char ch1, char ch2) const = 0;
    virtual ~IComparer() = default;
};

/**
 * @class CaseInsensitiveComparer
 * @brief Compares two characters ignoring case and delegates output.
 */
class CaseInsensitiveComparer : public IComparer {
private:
    const IValidator& validator;
    const IPrinter& printer;

    char toLower(char ch) const {
        return (ch >= 'A' && ch <= 'Z') ? (ch + 32) : ch;
    }

public:
    CaseInsensitiveComparer(const IValidator& val, const IPrinter& prn)
        : validator(val), printer(prn) {}

    void compare(char ch1, char ch2) const override {
        if (!validator.isValid(ch1) || !validator.isValid(ch2)) {
            printer.printError();
            return;
        }

        printer.printCase(ch1);
        printer.printCase(ch2);

        bool match = toLower(ch1) == toLower(ch2);
        printer.printMatch(match);

        if (!match) {
            printer.printOrder(ch1, ch2);
        }
    }
};

/**
 * @brief Main function to run the character comparison.
 * @return int Exit status.
 */
int main() {
    char ch1, ch2;

    std::cout << "Enter first character: ";
    std::cin >> ch1;

    std::cout << "Enter second character: ";
    std::cin >> ch2;

    AlphaValidator validator;
    ConsolePrinter printer;
    CaseInsensitiveComparer comparer(validator, printer);

    comparer.compare(ch1, ch2);

    return 0;
}
```
## Applications
- Sorting strings (e.g., dictionary order)
- Case-sensitive filters
- Custom character-based logic in games or parsers\
- Comparing user input for validation
