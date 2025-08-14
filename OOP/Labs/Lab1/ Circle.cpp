/**
 * @brief Program to calculate the area and circumference of a circle.
 *
 * This program takes the radius of a circle as input from the user,
 * validates the input, and calculates both the area and circumference
 * of the circle using the standard formulas:
 * 
 *      Area = π * r²
 *      Circumference = 2 * π * r
 *
 * The program also handles negative radius inputs by displaying an error message.
 *
 * @author Nitish Singh
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/**
 * @brief Main function to execute the circle calculations.
 *
 * Reads the radius from user input, computes the area and circumference
 * if the radius is positive, and displays the results.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
    cout << "\t\tC++ program to Calculate Area and Circumference of Circle. \n";

    float Radius;        ///< Radius of the circle entered by the user
    float Area;          ///< Computed area of the circle
    float Circumference; ///< Computed circumference of the circle

    /// Prompt user for radius
    cout << "Please enter the Radius of Circle: ";
    cin >> Radius;

    if (Radius > 0) {
        /// Formula: Area = π * r²
        Area = 3.14f * Radius * Radius;

        /// Formula: Circumference = 2 * π * r
        Circumference = 2 * 3.14f * Radius;

        cout << "Area of circle is " << Area << ";" << endl;
        cout << "Circumference of Circle is " << Circumference << ";" << endl;
    } else {
        cout << "Negative numbers cannot be applied !!!" << endl;
    }

    return 0;
}
