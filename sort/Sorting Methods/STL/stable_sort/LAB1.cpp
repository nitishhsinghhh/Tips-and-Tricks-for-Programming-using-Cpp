#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 1. STL Stable Sorting

class Solution {
public:
	// SortOrder 1 = Descending, 0 = Ascending Order
	enum Order {
		ASCENDING = 0,
		DESCENDING = 1
	};
	vector<int> stableStlSort(vector<int>& nums, Order order) {
		vector<int> res = nums;
		if (order == 1)
			stable_sort(res.begin(), res.end(), greater<int>());
		else
			stable_sort(res.begin(), res.end());
		return res;
	}
};

void main() {
	vector<int> vect{ 5,4,3,7,1,2 };

	Solution oSolution;
	vector<int> res = oSolution.stableStlSort(vect, Solution::ASCENDING);

	cout << "Sorted Elements: " << "{ ";
		for(int r : res)
			cout << r << " ";
		cout << "}" <<endl;

		res = oSolution.stableStlSort(vect, Solution::DESCENDING);

		cout << "Sorted Elements: " << "{ ";
		for (int r : res)
			cout << r << " ";
		cout << "}" << endl;

		system("pause");
}
