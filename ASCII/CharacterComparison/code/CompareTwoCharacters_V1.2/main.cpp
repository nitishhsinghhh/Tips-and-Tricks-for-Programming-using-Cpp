#include "AsciiComparator.hpp"
#include "MockPrinter.hpp"
#include <cassert>
#include <iostream>

// Use the same compareChars function as main
void compareChars(char ch1, char ch2, IPrinter* printer) {
    IComparator* comparator = new AsciiComparator(*printer);
    comparator->compare(ch1, ch2);
    delete comparator;
}

void testCompareChars() {
    MockPrinter mock;

    // Test 1: a < b
    compareChars('a', 'b', &mock);
    assert(mock.logs[0] == "ASCII:97");
    assert(mock.logs[1] == "ASCII:98");
    assert(mock.logs[2] == "A before B");
    mock.logs.clear();

    // Test 2: a == b
    compareChars('x', 'x', &mock);
    assert(mock.logs[0] == "ASCII:120");
    assert(mock.logs[1] == "ASCII:120");
    assert(mock.logs[2] == "Equal");
    mock.logs.clear();

    // Test 3: a > b
    compareChars('z', 'y', &mock);
    assert(mock.logs[0] == "ASCII:122");
    assert(mock.logs[1] == "ASCII:121");
    assert(mock.logs[2] == "B before A");

    std::cout << "All tests passed!\n";
}

int main() {
    testCompareChars();
    return 0;
}