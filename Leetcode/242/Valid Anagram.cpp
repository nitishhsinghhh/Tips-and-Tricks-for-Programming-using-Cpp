/**
 * 242. Valid Anagram 
 * (https://leetcode.com/problems/valid-anagram/description/)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        for(char ch: s){
            freq1[ch-'a']++;
        }
        for(char ch: t){
            freq2[ch-'a']++;
        }
        // check anagram or not 
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s, t;
    bool ans;

    // Test Case 1
    s = "rat";
    t = "car";
    ans = sol.isAnagram(s,t);
    ans ? cout<<"true": cout<<"false";
    cout<<endl;

    // Test Case 2
    s = "anagram";
    t = "nagaram";
    ans = sol.isAnagram(s,t);
    ans ? cout<<"true": cout<<"false";
    cout<<endl;

    // Test Case 3
    s = "program";
    t = "prolog";
    ans = sol.isAnagram(s,t);
    ans ? cout<<"true": cout<<"false";
    cout<<endl;

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