#include <iostream>
#include <string>
#include "VectorClass.h"

int main() {
    // Creating a VectorClass object of type string
    VectorClass<std::string> vec;
    // Adding three elements to the vector using push_back()
    vec.push_back("A");
    vec.push_back("B");
    vec.push_back("C");

    // Printing the element at index 2 using operator[]
    std::cout << "The vector at index 2 is: " << vec[2] << std::endl;

    // Printing all the elements of the vector using a for loop and operator[]
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    // Inserting a new element at index 2 using insertAt() and printing the
    // updated elements of the vector
    vec.insertAt("AA", 2);
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    // Removing the last element using pop_back() and printing the updated
    // elements of the vector
    vec.pop_back();
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    // Pausing the console
    system("pause");
}
