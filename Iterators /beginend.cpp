#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    // Declaring iterator to a vector
    vector<int>::iterator itr;

    // Displaying vector elements using begin() and end()
    cout << "The vector elements are: ";
    for (itr = vec.begin(); itr < vec.end(); ++itr) {
        cout << *itr << " ";
    }
    return 0;
}
