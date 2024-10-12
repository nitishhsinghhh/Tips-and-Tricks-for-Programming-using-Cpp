/**
 * 50. Pow(x,n) 
 * (https://leetcode.com/problems/powx-n/description/)
*/

#include<iostream>
class Solution {
private:
    double power(double x, int n){
        if(n==0) return 1;
        double partial_ans = power(x,n/2);
        double ans = partial_ans * partial_ans;
        if(n%2 != 0){
            ans *= x;
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        if(x==1 || x==0) return x;
        // To handle Negative number 
        if(n<0){
            x = 1/x;
        }
        return power(x,n);
    }
};

int main() {
	Solution sol;
    double x, n;
    double ans;
    
	// Test Case 1
	x = 2.00000;
	n = 10;
	ans = sol.myPow(x, n);
	std::cout<<"The output is: "<<ans<<std::endl;

	// Test Case 2
	x = 2.10000;
	n = 3;
	ans = sol.myPow(x, n);
	std::cout<<"The output is: "<<ans<<std::endl;

	// Test Case 3
	x = 2.00000;
	n = -2;
	ans = sol.myPow(x, n);
	std::cout<<"The output is: "<<ans<<std::endl;

	return 0;
}
/**
======================Output of Testcases===================
 
  Testcase 1:
    Input: x = 2.00000, n = 10
    Output: 1024.00000
---------------------------------------

  Testcase 2:
    Input: x = 2.10000, n = 3
    Output: 9.26100
---------------------------------------

  Testcase 3:
    Input: x = 2.00000, n = -2
    Output: 0.25000
    Explanation: 2-2 = 1/(2^2) = 1/4 = 0.25
 
 * */
