/*
  Leetcode Problem: 1347
  Problem link: (https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)
*/

#include<iostream>
#include<vector>

class Solution {
public:
    int minSteps(std::string s, std::string t) {
        // Declare two vectors as frequency array to count the number of characters of a string
        std::vector<int>f1(26,0);
        std::vector<int>f2(26,0);
        int i=0;
        // Count number of characters in string s and put the frequency of character of string s
        // in the index value of f1
        while(s[i] != 0){
            f1[s[i]-'a']++;
            i++;
        }
        i=0;
        // Count number of characters in string s and put the frequency of character of string t
        // in the index value of f2
        while(t[i] != 0){
            f2[t[i]-'a']++;
            i++;
        }
        // compare two frequncy array if both are same then return 0 as minimum steps number
        if(f1==f2) return 0;
        int res = 0;
        // count the difference between two strings
        for(int i=0;i<26;i++){
            int diff = abs(f1[i]-f2[i]);
            res += diff;
        }
        // as we have counted twice (to make one string others' equal) so dividing by 2 is our required 
        // minimum number of steps
        return res/2;
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







