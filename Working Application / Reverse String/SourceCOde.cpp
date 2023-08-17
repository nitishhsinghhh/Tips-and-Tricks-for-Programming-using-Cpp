#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int i = 0, j = s.size() - 1;
		while (i < j)
			swap(s[i++], s[j--]);
	}
};

int main() {
	Solution sol;
	vector<char> s;

	// Get input from user
	string input;
	cout << "Enter a string: ";
	getline(cin, input);

	// Convert input to vector<char>
	for (char c : input) 
		s.push_back(c);

	// Reverse the string using the Solution class
	sol.reverseString(s);

	// Print the reversed string
	cout << "Reversed string: ";
	for (char c : s) {
		cout << c;
	}
	cout << endl;

	system("pause");

	return 0;
}
