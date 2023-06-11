#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> newVec = {10, 20, 30};

    // Declaring iterator to a vector
    vector<int>::iterator itr = vec.begin();

    // Using advance() to set the position
    advance(itr, 3);

    // Copying elements from one vector to another using inserter()
    // Inserts newVec after the 3rd position in vec
    copy(newVec.begin(), newVec.end(), inserter(vec, itr));

    // Displaying new vector elements
    cout << "The new vector after inserting elements is: ";
    for (int& x : vec) {
        cout << x << " ";
    }
    return 0;
}

/*
Output:
The new vector after inserting elements is: 1 2 3 10 20 30 4 5
*/
