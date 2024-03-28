/**
*	  @File: beginend.cpp
*	  @Author: Nitish Singh
*	  @Date: March 28, 2024
*  	@Email: me.singhnitish@yandex.com

*   @Description:
*   This program demonstrates the use of iterators to iterate through a vector and print its elements to the console.
**/
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{ 1, 2, 3, 4, 5 };
    std::vector<int>::iterator itr;
    std::cout << "The vector elements are: ";
    for (itr = vec.begin(); itr < vec.end(); ++itr) 
        std::cout << *itr << " ";
    std::cout << std::endl;
    system("pause");
    return 0;
}
/**
The vector elements are: 1 2 3 4 5
Press any key to continue . . .
**/
