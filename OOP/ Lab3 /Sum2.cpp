// Program to display sum of series 1 + 3 + 5 + 7 + ... .. .

#include <iostream>
using namespace std;

class Solution {
public:
	int SumofSeries(int num) {
		int sum = 0;
		for (int i = 1; i <= num; i += 2)
			sum += i;
		return sum;
	}
};

int main() {
	int num;
	int sum = 0;
	Solution oSolution;
	cout << "Enter the value of n: ";
	cin >> num;
	int res = oSolution.SumofSeries(num);
	cout << "Sum is : " << res << endl;
	system("pause");
	return 0;
}
