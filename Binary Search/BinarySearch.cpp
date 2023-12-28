/**
 * Binary Search: (Binary search is a divide-and-conquer algorithm that can be used to find the position of a target value within a sorted array.)
*/
#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int>&nums, int search_key){
    int ans_index = -1;
    int left = 0;
    int right = nums.size()-1;
    int mid;
    while(left <= right){
        //calculate mid index
        mid = left + (right - left)/2;
        if(nums[mid] == search_key){
            ans_index = mid;
            break;
        }
        else if(nums[mid] < search_key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans_index;
}
int main(){
    vector<int>numbers={4,6,7,12,9,3,6,7};
    int search_key = 6;
    int res;
    // sort the given array before calling binary search
    sort(numbers.begin(), numbers.end());

    // calling the binary search funtion to kind the element is present or not
    // test case 1
    res = binary_search(numbers, search_key);
    if(res == -1){
        cout<<"Element is not found"<<endl;
    }
    else{
        cout<<"Element has found"<<endl;
    }

    // test case 2
    res = binary_search(numbers, 5);
    if(res == -1){
        cout<<"Element is not found"<<endl;
    }
    else{
        cout<<"Element has found"<<endl;
    }

    return 0;
}

/**
 * ---------Output of the test cases-------
 * 
 * test case 1: 
 * Output-> Element has found
 * 
 * test case 2:
 * Output-> Element is not found
*/