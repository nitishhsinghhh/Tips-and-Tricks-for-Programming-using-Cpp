#include <iostream>
#include <string>
using namespace std;

string vowels = "aeiouAEIOU";
bool halvesAreAlike(string S) {
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
	string test1 = "book";
	string test2 = "textbook";
	string test3 = "AbCdEfGh";

	cout << "Test 1: " << (halvesAreAlike(test1) ? "true" : "false") << endl;
	cout << "Test 2: " << (halvesAreAlike(test2) ? "true" : "false") << endl;
	cout << "Test 3: " << (halvesAreAlike(test3) ? "true" : "false") << endl;

}

/*
Output:
Test 1: true
Test 2: false
Test 3: true

*/
