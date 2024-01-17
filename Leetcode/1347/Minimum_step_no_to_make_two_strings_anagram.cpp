/*
  Leetcode Problem: 1347
  Problem link: (https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)
*/

#include<iostream>
#include<vector>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        // Declare two unordered maps to store the frequency of characters in each string
        std::unordered_map<char, int> freqS, freqT;

        // Count the frequency of characters in string s
        for (char ch : s) {
            freqS[ch]++;
        }

        // Count the frequency of characters in string t
        for (char ch : t) {
            freqT[ch]++;
        }

        int res = 0;

        // Iterate through the frequency map of string s
        for (auto it = freqS.begin(); it != freqS.end(); it++) {
            char currentChar = it->first;
            int freqDifference = it->second - freqT[currentChar];

            // Add only positive differences to the result
            if (freqDifference > 0) {
                res += freqDifference;
            }
        }

        return res;
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







