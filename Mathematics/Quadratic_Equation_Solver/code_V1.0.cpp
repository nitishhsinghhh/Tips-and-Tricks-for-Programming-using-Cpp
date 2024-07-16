// A program that solves a quadratic equation (ax^2 + bx + c = 0).
// Taking coefficients a, b, and c as input.
#include <iostream>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    // Calculate the value of discriminant
    double discriminant = b * b - 4 * a * c;
    std::cout << discriminant << std::endl;
    // Check if the discriminant is positive, negative or zero
    if (discriminant > 0) {
        // Exists two real and distinct roots
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "Root 1: " << root1 << std::endl;
        std::cout << "Root 2: " << root2 << std::endl;
    } else if (discriminant == 0) {
        // Exists one real root
        double root = (-b) / (2 * a);
        std::cout << "Root :" << root << std::endl;
    } else {
        double realPart = (-b / (2 * a));
        if (b == 0)
            realPart = 0;
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        std::cout << "Root 1: " << realPart << " + " << imaginaryPart << "i\n";
        std::cout << "Root 2: " << realPart << " - " << imaginaryPart << "i\n";
    }
    std::cout << "Bye\n";
    return 0;
}

/*
========================OUPUT SECTION=====================================
  Input: a = 4, b = -3, c = -6
  Output:
    Root 1: 1.65587
    Root 2: -0.905869
-------------------------------------
  Input: a = 2, b = 0, c = 5
` Ouput:
    Root 1: 0 + 1.58114i
    Root 2: 0 - 1.58114i
-------------------------------------
  Input: a = 2, b = 4, c = 2
  Output:
    Root :-1
==========================================================================
*/

/*
=======================TOPIC DISCUSSION===================================
  The discriminant is a term used in the context of quadratic equations,
  and it is part of the quadratic formula.
  For a quadratic equation in the form (ax^2 + bx + c = 0),
  the discriminant is given by the expression inside the square root of the
quadratic formula:

  [Discriminant = b^2 - 4ac]

  The discriminant plays a crucial role in determining the nature of the roots
(solutions) of the quadratic equation. Its value provides information about
whether the roots are real or complex and whether they are distinct or repeated.

  The discriminant can take on three different cases:

  1. If Discriminant > 0:
   - Two distinct real roots exist.

  2. If Discriminant = 0:
   - There is one real root (a repeated or double root).

  3. If Discriminant < 0:
   - The roots are complex conjugates (they have both real and imaginary parts).


  The discriminant helps in classifying the solutions and is a fundamental
concept when dealing with quadratic equations and their graphical
representation. In programming, it is often used to guide the branching logic in
solving quadratic equations.
*/
