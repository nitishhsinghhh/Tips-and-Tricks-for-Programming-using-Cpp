#include <iostream>

/**
 * @class PrintDecreaseIncrease
 * @brief A class to print numbers in decreasing and then increasing order using recursion.
 */
class PrintDecreaseIncrease {
private:
    int n;

    /**
     * @brief Recursive function to print numbers in decreasing and then increasing order.
     * 
     * @param n Reference to the number to be printed.
     */
    void pdi(int &n) {
        if (n == 0) return;
        std::cout << n << std::endl;
        pdi(--n);
        std::cout << ++n << std::endl;
    }

public:
    /**
     * @brief Constructor to initialize the class with a number.
     * 
     * @param num The number to start the recursive printing from.
     */
    PrintDecreaseIncrease(int num) : n(num) {}

    /**
     * @brief Public method to invoke the recursive print function.
     */
    void printPDI() {
        std::cout << "Print Decrease & Increase:\n";
        pdi(n);
    }
};

/**
 * @brief Main function to handle user input and run the program.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    int inputNumber;

    // Handle non-positive input values
    do {
        std::cout << "Enter a number: ";
        std::cin >> inputNumber;
        if (inputNumber <= 0) {
            std::cout << "Please give positive number as input!\n";
        }
    } while (inputNumber <= 0);

    // Create object of PrintDecreaseIncrease class
    PrintDecreaseIncrease obj(inputNumber);

    // Call the print function
    obj.printPDI();

    return 0;
}

/**
 * ==================== OUTPUT SECTION ==========================
 * Input: n = 4
 * Output: 4
 *         3
 *         2
 *         1
 *         1
 *         2
 *         3
 *         4
 * -----------------
 * Input: 2
 * Output: 2
 *         1
 *         1
 *         2
 * -----------------
 * Input: 1
 * Output: 1
 *         1
 * ==============================================================
 */
