/***
 *  File: main.cpp
 *  Description: This program demonstrates the use of the MathInterface and LCM
 *classes to calculate the GCD and LCM of two numbers. Author: Nitish Singh
 *  Date: January 5, 2024 || Updated on July 16, 2024
 *  Contact: singhnitish@yandex.com
 ***/

#include <iostream>

// MathInterface serves as the interface for GCD and LCM calculations
class MathInterface {
public:
    virtual int gcd(int a, int b) = 0;
    virtual long long lcm(int a, int b) = 0;
};

class LCM : public MathInterface {
private:
    int a, b;

    /***
     * Calculates the GCD of two numbers using the Euclidean algorithm.
     * @param a The first number
     * @param b The second number
     * @return The GCD of the two numbers
     **/
    int calculateGCD(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

    /***
     * Calculates the LCM of two numbers using the GCD.
     * @param x The first number
     * @param y The second number
     * @return The LCM of the two numbers
     **/
    long long calculateLCM(int x, int y) {
        long long mul = x;
        mul *= y;
        long long res = mul / calculateGCD(x, y);
        return res;
    }

public:
    /***
     * Constructor for the LCM class.
     * @param _a The first number
     * @param _b The second number
     **/
    LCM(int _a, int _b) : a(_a), b(_b) {}

    int gcd(int a, int b) override { return calculateGCD(a, b); }

    long long lcm(int a, int b) override { return calculateLCM(a, b); }
};

void testMathInterface(MathInterface& mathObj, int num1, int num2) {
    int result_gcd = mathObj.gcd(num1, num2);
    long long result_lcm = mathObj.lcm(num1, num2);

    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << result_gcd
              << std::endl;
    std::cout << "LCM of " << num1 << " and " << num2 << " is: " << result_lcm
              << std::endl;
}

int main() {
    LCM lcm(0, 0); // Instantiate the LCM class

    // Test cases
    int test_cases[10][2] = {{15, 25}, {18, 24}, {7, 5},   {30, 42}, {8, 12},
                             {17, 23}, {35, 49}, {22, 14}, {45, 27}, {11, 13}};

    for (int i = 0; i < 10; i++) {
        std::cout << "Test Case " << i + 1 << ":" << std::endl;
        testMathInterface(lcm, test_cases[i][0], test_cases[i][1]);
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}

/**
 *   Test Case 1:
 *	  GCD of 15 and 25 is: 5
 *	  LCM of 15 and 25 is: 75
 *
 *	  Test Case 2:
 *	  GCD of 18 and 24 is: 6
 *	  LCM of 18 and 24 is: 72
 *
 *	  Test Case 3:
 *	  GCD of 7 and 5 is: 1
 *	  LCM of 7 and 5 is: 35
 *
 *	  Test Case 4:
 *	  GCD of 30 and 42 is: 6
 *	  LCM of 30 and 42 is: 210
 *
 *	  Test Case 5:
 *  	GCD of 8 and 12 is: 4
 *	  LCM of 8 and 12 is: 24
 *
 *	  Test Case 6:
 *	  GCD of 17 and 23 is: 1
 *	  LCM of 17 and 23 is: 391
 *
 *	  Test Case 7:
 *  	GCD of 35 and 49 is: 7
 *	  LCM of 35 and 49 is: 245
 *
 *	  Test Case 8:
 *	  GCD of 22 and 14 is: 2
 *	  LCM of 22 and 14 is: 154
 *
 *	  Test Case 9:
 *	  GCD of 45 and 27 is: 9
 *	  LCM of 45 and 27 is: 135
 *
 *  	Test Case 10:
 *	  GCD of 11 and 13 is: 1
 *  	LCM of 11 and 13 is: 143
 *
 *	  Press any key to continue . . .
 *
 **/
