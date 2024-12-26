#include "passByValue.h"

using std::vector;
using std::min;

int passByValue::smallest_element(vector<int> vec) {
	auto smallest_val = vec[0];
	for (auto x : vec)
		smallest_val = min(smallest_val, x);
	return smallest_val;
}
