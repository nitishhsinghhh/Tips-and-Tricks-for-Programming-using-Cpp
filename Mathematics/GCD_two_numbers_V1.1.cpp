/***
*  File: main.cpp
*  Description: This program demonstrates the use of the MathInterface and LCM classes to calculate the GCD and LCM of two numbers.
*  Author: Nitish Singh
*  Date: January 5, 2024
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
	int calculateGCD(int a, int b) {
		if (a == 0) return b;
		else if (b == 0) return a;
		if (a == b) return b;
		if (a > b) return calculateGCD(a % b, b);
		else return calculateGCD(a, b % a);
	}

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

	int gcd(int a, int b) override {
		return calculateGCD(a, b);
	}

	long long lcm(int a, int b) override {
		return calculateLCM(a, b);
	}
};

void testMathInterface(MathInterface& mathObj, int num1, int num2) {
	int result_gcd = mathObj.gcd(num1, num2);
	long long result_lcm = mathObj.lcm(num1, num2);

	std::cout << "GCD of " << num1 << " and " << num2 << " is: " << result_gcd << std::endl;
	std::cout << "LCM of " << num1 << " and " << num2 << " is: " << result_lcm << std::endl;
}

int main() {
	int a, b;
	std::cout << "Enter two numbers: ";
	std::cin >> a >> b;
	LCM lcm(a, b);
	testMathInterface(lcm, a, b);
  system("pause");
	return 0;
}

/**
*  Enter two numbers: 8 12
*  GCD of 8 and 12 is: 4
*  LCM of 8 and 12 is: 24
*  Press any key to continue . . .
**/
