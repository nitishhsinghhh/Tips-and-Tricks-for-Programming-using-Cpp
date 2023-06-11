#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    // Declaring iterators to a vector
    vector<int>::iterator itr = vec.begin();
    vector<int>::iterator ftr = vec.end();

    // Using next() to return a new iterator
    auto newItr = next(itr, 3);

    // Using prev() to return a new iterator
    auto newFtr = prev(ftr, 3);

    // Displaying iterator positions
    cout << "The position of the new iterator using next() is: " << *newItr << endl;
    cout << "The position of the new iterator using prev() is: " << *newFtr << endl;

    return 0;
}
