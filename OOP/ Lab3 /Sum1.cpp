// Program to display sum of series 1 + 1/2 + 1/3 + 1/4 ... .. .

#include <iostream>
using namespace std;

class Solution {
public:
	float SumofSeries(int num) {
		float sum = 0;
		for (int i = 1; i <= num; i++)
			sum += (float)1/i;
		return sum;
	}
};

int main() {
	int num;
	float sum = 0;
	Solution oSolution;
	cout << "Enter the value of n: ";
	cin >> num;
	float res = oSolution.SumofSeries(num);
	cout << "Sum is : " << res << endl;
	system("pause");
	return 0;
}
