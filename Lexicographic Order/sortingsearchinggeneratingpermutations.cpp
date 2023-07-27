#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str1 = "apple";
    string str2 = "banana";
    if (str1 < str2) {
        cout << str1 << " comes before " << str2 << endl;
    }

    vector<string> fruits = {"banana", "apple", "cherry"};
    sort(fruits.begin(), fruits.end());

    vector<int> nums = {1, 2, 3};
    do {
        // Process current permutation
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

    // Additional testing
    cout << "Sorted fruits: ";
    for (int i = 0; i < fruits.size(); i++) {
        cout << fruits[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
apple comes before banana
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
Sorted fruits: apple banana cherry 
*/
