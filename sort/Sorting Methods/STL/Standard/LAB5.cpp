#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	// SortOrder 1 = Descending, 0 = Ascending Order
	enum Order {
		ASCENDING = 0,
		DESCENDING = 1
	};
	vector<int> stlSort(vector<int>& nums, Order order) {
		vector<int> res = nums;
		if (order == DESCENDING)
			sort(res.begin(), res.end(), greater<int>());
		else
			sort(res.begin(), res.end());
		return res;
	}
};

int main() {
	vector<int> vect{ 5,4,3,7,1,2 };

	Solution oSolution;
	vector<int> res = oSolution.stlSort(vect, Solution::ASCENDING);

	cout << "Sorted Elements (Ascending Order): " << "{ ";
	for (int r : res)
		cout << r << " ";
	cout << "}" << endl;

	res = oSolution.stlSort(vect, Solution::DESCENDING);

	cout << "Sorted Elements (Descending Order): " << "{ ";
	for (int r : res)
		cout << r << " ";
	cout << "}" << endl;

	system("pause");
	return 0;
}

/*
Output:
Sorted Elements (Ascending Order): { 1 2 3 4 5 7 }
Sorted Elements (Descending Order): { 7 5 4 3 2 1 }
*/
