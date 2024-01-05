#include <iostream>
std::string vowels = "aeiouAEIOU";
bool halvesAreAlike(std::string S) {
	int mid = S.size() / 2, ans = 0;
	for (int i = 0, j = mid; i < mid; i++, j++) {
		if (~vowels.find(S[i]))
			ans++;
		if (~vowels.find(S[j]))
			ans--;
	}
	return ans == 0;
}

void main() {
	// Test cases
	std::string test1 = "book";
	std::string test2 = "textbook";
	std::string test3 = "AbCdEfGh";

	std::cout << "Test 1: " << (halvesAreAlike(test1) ? "true" : "false") << std::endl;
	std::cout << "Test 2: " << (halvesAreAlike(test2) ? "true" : "false") << std::endl;
	std::cout << "Test 3: " << (halvesAreAlike(test3) ? "true" : "false") << std::endl;

	system("pause");
}

/**
* Test 1: true
* Test 2: false
* Test 3: true
* Press any key to continue . . .
**/

