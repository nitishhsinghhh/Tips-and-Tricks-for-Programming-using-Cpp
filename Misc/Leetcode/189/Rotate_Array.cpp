/*
********************************************************************************
Leetcode Problem Number: 189
Problem Link: https://leetcode.com/problems/rotate-array/

********************************************************************************
*/

#include<iostream>
#include<vector>
#include<algorithm> // for std::reverse

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        // right rotate
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end());
    }
};
// A function to print the array elements 
void printArray(std::vector<int>&nums){
  for(int num: nums)
    std::cout<<num<<" ";
  std::cout<<std::endl;
}
// main function 
int main(){
  // Create an instance of Solution class named sol
  Solution sol;
  
  // -------------Testcase 1--------------------
  // Create an array 
  std::vector<int>nums1 = {1,2,3,4,5,6};
  // define number of rotation
  int k1 = 2;
  // get the rotated array
  sol.rotate(nums1, k1);
  // print the array 
  std::cout<<"After rotating by "<< k1 <<" steps: ";
  printArray(nums1);

  // -------------Testcase 2--------------------
  // Create an array 
  std::vector<int>nums2 = {5, 7, -8, 9};
  // define number of rotation
  int k2 = 7;
  // get the rotated array
  sol.rotate(nums2, k2);
  // print the array 
  std::cout<<"After rotating by "<< k2 <<" steps: ";
  printArray(nums2);

  // -------------Testcase 3--------------------
  // Create an array 
  std::vector<int>nums3 = {100, -5, 13, 8, 9, 3, 5, 8, 9, 4, 7};
  // define number of rotation
  int k3 = 5;
  // get the rotated array
  sol.rotate(nums3, k3);
  // print the array 
  std::cout<<"After rotating by "<< k3 <<" steps: ";
  printArray(nums3);
  
  return 0;
}


/*
========================OUTPUT==============================================================
Testcase 1:
-----------
Input:  arr = [1,2,3,4,5,6], k = 2
Output: arr = [5 6 1 2 3 4] 

------------------------------------------------------------------------------------

Testcase 2:
-----------
Input:  arr = [5, 7, -8, 9], k = 7
Output: arr = [7 -8 9 5] 

-------------------------------------------------------------------------------------

Testcase 3:
Input:  arr = [100, -5, 13, 8, 9, 3, 5, 8, 9, 4, 7], k = 5
Output: arr = [5 8 9 4 7 100 -5 13 8 9 3]
=============================================================================================
*/
