#include <iostream>
#include <stdexcept>

double divideNumbers(double dividend, double divisor) {
    if (divisor == 0)
        throw std::runtime_error("Division by zero error!");

    return dividend / divisor;
}

int main() {
    try {
        double result = divideNumbers(10.0, 0.0);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
