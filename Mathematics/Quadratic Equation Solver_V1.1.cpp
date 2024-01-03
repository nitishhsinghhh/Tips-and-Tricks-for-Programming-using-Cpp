/**
 * @file quadratic_equation_solver.cpp
 * @brief This program solves a quadratic equation based on user input.
 * @author Nitish Singh
 * @date January 3, 2024
 */

#include <iostream>
#include <cmath>

class QuadraticEquationSolver {
private:
	double a, b, c;

public:
	QuadraticEquationSolver(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

	double calculateDiscriminant() {
		return b * b - 4 * a * c;
	}

	void solve() {
		double discriminant = calculateDiscriminant();
		std::cout << "Discriminant: " << discriminant << std::endl;

		if (discriminant > 0) {
			// Two real and distinct roots
			double root1 = (-b + sqrt(discriminant)) / (2 * a);
			double root2 = (-b - sqrt(discriminant)) / (2 * a);
			std::cout << "Root 1: " << root1 << std::endl;
			std::cout << "Root 2: " << root2 << std::endl;
		}
		else if (discriminant == 0) {
			// One real root
			double root = (-b) / (2 * a);
			std::cout << "Root: " << root << std::endl;
		}
		else {
			// Two complex roots
			double realPart = (-b / (2 * a));
			double imaginaryPart = sqrt(-discriminant) / (2 * a);
			std::cout << "Root 1: " << realPart << " + " << imaginaryPart << "i\n";
			std::cout << "Root 2: " << realPart << " - " << imaginaryPart << "i\n";
		}
	}
};

int main() {
	double a, b, c;
	std::cout << "Enter the coefficients (a, b, c) of the quadratic equation, seperated by space: ";
	std::cin >> a >> b >> c;

	QuadraticEquationSolver solver(a, b, c);
	solver.solve();

	system("pause");
	return 0;
}

/*
Enter the coefficients (a, b, c) of the quadratic equation, seperated by space: 12 13 14
Discriminant: -503
Root 1: -0.541667 + 0.934486i
Root 2: -0.541667 - 0.934486i
Press any key to continue . . .
*/
