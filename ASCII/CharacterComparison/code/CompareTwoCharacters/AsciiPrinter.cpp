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
