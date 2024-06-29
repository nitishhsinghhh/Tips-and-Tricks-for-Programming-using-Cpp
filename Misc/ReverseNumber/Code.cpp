#include <iostream>
#include <algorithm>
#include <string>

// Function to reverse a number
int reverseNumber(int num) {
    // Convert the number to a string
    std::string numStr = std::to_string(num);
    
    // Reverse the string
    std::reverse(numStr.begin(), numStr.end());
    
    // Convert the reversed string back to an integer
    int reversedNum = std::stoi(numStr);
    
    return reversedNum;
}

// Function to test reverseNumber with multiple test cases
void testReverseNumber() {
    int testCases[10] = {123, 456, 789, 1020, 1001, 9876, 54321, 6789, 20202, 111};
    int expectedResults[10] = {321, 654, 987, 201, 1001, 6789, 12345, 9876, 20202, 111};
    
    for (int i = 0; i < 10; ++i) {
        int result = reverseNumber(testCases[i]);
        std::cout << "Test case " << i + 1 << ": Input = " << testCases[i]
                  << ", Expected output = " << expectedResults[i]
                  << ", Actual output = " << result
                  << " -> " << (result == expectedResults[i] ? "Passed" : "Failed")
                  << std::endl;
    }
}

int main() {
    // Call the test function
    testReverseNumber();
    
    return 0;
}
