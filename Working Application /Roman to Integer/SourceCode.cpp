#include <iostream>
#include<istream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		vector<int> Key = { 8,21,23,11,2,3,12 };
		vector<int> value = { 1, 5, 10, 50, 100, 500, 1000 };
		int res = 0, tKey = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			auto cKey = find(Key.begin(), Key.end(), (s[i] - 'A'));
			if (cKey != Key.end()) {
				int index = distance(Key.begin(), cKey);
				if (tKey > index)
					res -= value[index];
				else
					res += value[index];
				tKey = index;
			}
		}
		return res;
	}
};


int main() {
	cout << "Roman numerals are usually written from largest to smallest, left to right. However, in some cases, subtraction\n"
		<< "is used. For example, the numeral for four is not IIII but IV, which means that we subtract one(I) from five(V)\n"
		<< "to get four. The same principle applies to the number nine, which is written as IX. There are six instances where\n"
		<< "subtraction is used: \n"
		<< "- I can be placed before V (5) and X (10) to make 4 and 9.\n"
		<< "- X can be placed before L (50) and C (100) to make 40 and 90.\n"
		<< "- C can be placed before D (500) and M (1000) to make 400 and 900." << endl;
	
	cout << endl;

	cout << "Roman numerals use seven different symbols to represent numbers. The symbols and their corresponding values are:\n"
		<< "- I represents 1\n"
		<< "- V represents 5\n"
		<< "- X represents 10\n"
		<< "- L represents 50\n"
		<< "- C represents 100\n"
		<< "- D represents 500\n"
		<< "- M represents 1000\n"
		<< "When writing a number in Roman numerals, a combination of these symbols is used to represent the value of the number." << endl;
	
	Solution oSolution;
	string romans[] = { "III", "IV", "IX", "LVIII", "MCMXCIV" };
	for (string roman : romans)
		cout << roman << ": The Equivalent integer value is: " << oSolution.romanToInt(roman) << endl;

	cout << endl;
	string input;

	cout << endl << "Please enter a Roman numeral to be converted (in the range [1, 3999]): " << endl;

	cin >> input;
	int res = oSolution.romanToInt(input);
	cout << "The equivalent integer value is: " << res << endl;

	system("pause");
}
