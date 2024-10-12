// Program to sum the series up to n

#include<iostream>
using namespace std;

class Solution {
public:
	double qwerty(double n, double sum, double fact) {
		for (int i = 1; i <= n; i++) {
			fact = fact * i;			
			sum += (pow(i, i) / (fact)); 
		}								
		return sum;						
	}
};

void main() {
	double n;
	double sum = 0;
	double fact = 1;
	cout << "Please enter the number: "; 
	cin >> n;
	Solution oSolution;
	if (n > 0)												
		cout << "Sum is: " << oSolution.qwerty(n, sum, fact) << endl; 
	else													
		cout << "INVALID INPUT!" << endl;
	system("pause");
}
