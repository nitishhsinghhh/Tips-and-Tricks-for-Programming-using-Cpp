/**
 * 242. Valid Anagram
 * (https://leetcode.com/problems/valid-anagram/description/)
*/

#include<iostream>
#include<vector>

class Solution {
public:
	bool isAnagram(std::string s, std::string t) {
		// Declare an array to store the frequency of characters of the string
		std::vector<int>freq(26, 0);

		// Increment the frequency of characters in the array for string s
		for (char ch : s) {
			freq[ch - 'a']++;
		}

		// Decrement the frequency of characters in the array for string t
		for (char ch : t) {
			freq[ch - 'a']--;
		}

		// Check if all frequencies in the array are zero
		for (int val : freq) {
			// If any frequency is non-zero, strings are not anagrams
			if (val != 0) return false;
		}
		// If all frequencies are zero, strings are anagarams
		return true;
	}
};

int main() {
	Solution sol;
	std::string s, t;
	bool ans;

	// Test Case 1
	s = "rat";
	t = "car";
	ans = sol.isAnagram(s, t);
	ans ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;

	// Test Case 2
	s = "anagram";
	t = "nagaram";
	ans = sol.isAnagram(s, t);
	ans ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;

	// Test Case 3
	s = "program";
	t = "prolog";
	ans = sol.isAnagram(s, t);
	ans ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;

	return 0;
}
/**
 * --------Output of Testcases--------
 *
 * Input: s = "rat", t = "car"
 * Output: false
 *
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 * Input: s = "program", t = "prolog"
 * Output: false
 *
 * */
