#include <iostream>
#include <vector>
#include<string>
#include <algorithm>

int main() {
	std::string str1 = "apple";
	std::string str2 = "banana";
	if (str1 < str2) 
		std::cout << str1 << " comes before " << str2 << std::endl;

	std::vector<std::string> fruits = { "banana", "apple", "cherry" };
	sort(fruits.begin(), fruits.end());

	std::vector<int> nums = { 1, 2, 3 };
	do {
		// Process current permutation
		for (int i = 0; i < nums.size(); i++) 
			std::cout << nums[i] << " ";
		std::cout << std::endl;
	} while (next_permutation(nums.begin(), nums.end()));

	// Additional testing
	std::cout << "Sorted fruits: ";
	for (int i = 0; i < fruits.size(); i++) 
		std::cout << fruits[i] << " ";
	std::cout << std::endl;

	system("pause");
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
