#include "IComparator.hpp"
#include "IPrinter.hpp"

/**
 * @class AsciiComparator
 * @brief Compares two characters and delegates printing.
 */
class AsciiComparator : public IComparator {
private:
    IPrinter* printer;

public:
    /**
     * @brief Constructor with dependency injection.
     * @param p Pointer to a printer object.
     */
    AsciiComparator(IPrinter* p) : printer(p) {}

    void compare(char a, char b) override {
        printer->printAscii(a);
        printer->printAscii(b);
        printer->printComparison(a, b);
    }
};