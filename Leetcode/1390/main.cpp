#include "solution.hpp"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
    Solution sol;

    vector<int> nums1 = {21, 4, 7};
    vector<int> nums2 = {21, 21};
    vector<int> nums3 = {1, 2, 3, 4, 5};
    vector<int> nums4 = {8};
    vector<int> nums5 = {10};
    vector<int> nums6 = {27};
    vector<int> nums7 = {14, 15, 22};

    cout << "Test 1: " << sol.sumFourDivisors(nums1) << " Expected: 32" << endl;
    cout << "Test 2: " << sol.sumFourDivisors(nums2) << " Expected: 64" << endl;
    cout << "Test 3: " << sol.sumFourDivisors(nums3) << " Expected: 0" << endl;
    cout << "Test 4: " << sol.sumFourDivisors(nums4) << " Expected: 15" << endl;
    cout << "Test 5: " << sol.sumFourDivisors(nums5) << " Expected: 18" << endl;
    cout << "Test 6: " << sol.sumFourDivisors(nums6) << " Expected: 40" << endl;
    cout << "Test 7: " << sol.sumFourDivisors(nums7) << " Expected: 84" << endl;

    return 0;
}