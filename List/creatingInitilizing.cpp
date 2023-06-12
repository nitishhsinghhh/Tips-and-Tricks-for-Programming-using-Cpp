#include <iostream>
#include <list>
using namespace std;

void main() {
 list<int> myList{ 1, 2, 3, 4, 5 };
 // Accessing elements using a range-based for loop
 for (auto element : myList) 
  cout << element << " ";
}

// output: 1 2 3 4 5.
