/**
 * 50. Pow(x,n) 
 * (https://leetcode.com/problems/powx-n/description/)
*/

#include<iostream>
class Solution {
public:
    double myPow(double x, int n) {
       if(x==0) return 0;
        // If n is equal to 0 return 1 (something to the power 0 is 1) or x is 1
        if(x==1 || n==0) return 1;
        // if n is less than 0 then make the x to its reciprocal and n as postive number
        if (n < 0){
            n = abs(n);
            x = 1/x;
        }
        // Calculate half by recursively calling myPow with x and n/2
        double half = myPow(x, n / 2);
        // if n is even return the square of half
        // and if n is odd then return the square of half multiplied by x 
        return (n % 2 == 0) ? half * half : half * half * x;
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
