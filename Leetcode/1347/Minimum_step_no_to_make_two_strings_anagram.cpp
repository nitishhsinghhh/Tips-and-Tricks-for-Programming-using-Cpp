/*
  Leetcode Problem: 1347
  Problem link: (https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)
*/

#include<iostream>
#include<string>
#include<unordered_map>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        // Create an unordered map to store the frequency difference of characters
        std::unordered_map<char, int> freqDifference;

        // Count the frequency of characters in string s
        for (char ch : s) {
            freqDifference[ch]++;
        }

        // Subtract the frequency of characters in string t
        for (char ch : t) {
            freqDifference[ch]--;
        }

        // Initialize the result variable
        int res = 0;

        // Iterate over the key-value pairs in the frequency difference map
        for (const auto& [key, value] : freqDifference) {
            // Add the absolute value of the frequency difference to the result
            res += abs(value);
        }

        // Return the final result, divided by 2 as each difference contributes twice
        return res / 2;
    }
};

int main(){
    // Creating an object of Solution Class
    Solution sol;
    
    std::string str1, str2;
    int res;
    // test case 1 
    str1 = "bab";
    str2 = "aba";
    res = sol.minSteps(str1, str2);
    std::cout<<"To make '"<<str1<<"' and '"<<str2<<"' anagrams, only "<<res<<" step is needed."<<std::endl;
    // test case 2
    str1 = "leetcode";
    str2 = "practice";
    res = sol.minSteps(str1,str2);
    std::cout<<"To make '"<<str1<<"' and '"<<str2<<"' anagrams, only "<<res<<" step is needed."<<std::endl;
    return 0;
}


/*
=====================OUTPUT SECTION=============================
Testcase 1:
Input: s = "anagram", t = "mangaar"
Output: To make 'anagram' and 'mangaar' anagrams, only 0 step is needed.
------------------------------------
Testcase 2:
Input: s = "anupama", s = "haldera"
Output: To make 'anupama' and 'haldera' anagrams, only 5 step is needed.
------------------------------------
Testcase 3:
Input: s = "bab", t = "aba"
Output: To make 'bab' and 'aba' anagrams, only 1 step is needed.
 
=================================================================
*/







