#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    // Declaring iterator to a vector
    vector<int>::iterator itr = vec.begin();

    // Using advance() to increment iterator position
    advance(itr, 3);

    // Displaying iterator position
    cout << "The position of the iterator after advancing is: " << *itr << endl;

    return 0;
}
