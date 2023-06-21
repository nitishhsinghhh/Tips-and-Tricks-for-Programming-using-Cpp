#include <iostream>
#include <list>
using namespace std;

void runTestCase(const list<int>& initialList) {
    // Create a copy of the initial list
    list<int> dblList = initialList;

    // Find the middle iterator
    auto middleIterator = dblList.begin();
    advance(middleIterator, dblList.size() / 2);

    // Delete the middle element
    dblList.erase(middleIterator);

    // Print the updated list
    for (const auto& element : dblList)
        cout << element << " ";

    cout << endl;
}

int main() {
    // Test Case 1: Deleting the middle element from an odd-sized list
    cout << "Test Case 1: Deleting the middle element from an odd-sized list" << endl;
    list<int> testCase1 = {1, 2, 3, 4, 5};
    runTestCase(testCase1); // Expected output: 1 2 4 5

    // Test Case 2: Deleting the middle element from an even-sized list
    cout << "Test Case 2: Deleting the middle element from an even-sized list" << endl;
    list<int> testCase2 = {10, 20, 30, 40, 50, 60};
    runTestCase(testCase2); // Expected output: 10 20 40 50 60

    // Test Case 3: Deleting the only element from the list
    cout << "Test Case 3: Deleting the only element from the list" << endl;
    list<int> testCase3 = {100};
    runTestCase(testCase3); // Expected output:

    // Test Case 4: Deleting the first element from the list
    cout << "Test Case 4: Deleting the first element from the list" << endl;
    list<int> testCase4 = {1, 2, 3, 4, 5};
    runTestCase(testCase4); // Expected output: 2 3 4 5

    // Test Case 5: Deleting the last element from the list
    cout << "Test Case 5: Deleting the last element from the list" << endl;
    list<int> testCase5 = {10, 20, 30, 40, 50};
    runTestCase(testCase5); // Expected output: 10 20 30 40

    // Test Case 6: Deleting from an empty list
    cout << "Test Case 6: Deleting from an empty list" << endl;
    list<int> testCase6 = {};
    runTestCase(testCase6); // Expected output:

    return 0;
}

/*
Output:
Test Case 1: Deleting the middle element from an odd-sized list
1 2 4 5 
Test Case 2: Deleting the middle element from an even-sized list
10 20 30 50 60 
Test Case 3: Deleting the only element from the list

Test Case 4: Deleting the first element from the list
1 2 4 5 
Test Case 5: Deleting the last element from the list
10 20 40 50 
Test Case 6: Deleting from an empty list
double free or corruption (out)
Aborted
*/
