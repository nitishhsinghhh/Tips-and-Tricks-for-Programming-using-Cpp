// C++ program to demonstrate default behaviour of
// sort() in STL.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<pair<int, int>> nums{ { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
	int n = nums.size();

	// Sort the vector of pairs according to the starting times
	sort(nums.begin(), nums.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.first < b.first;
	});

	cout << "Sorted nums vector according to starting times: { ";
	for (int i = 0; i < n; ++i) {
		cout << "{ " << nums[i].first << ", " << nums[i].second << " }";
		if (i != n - 1) 
			cout << ", ";
	}
	cout << " }";

	return 0;
}


/*
Output:
Sorted nums vector according to starting times: { { 1, 9 }, { 2, 4 }, { 4, 7 }, { 6, 8 } }
*/
