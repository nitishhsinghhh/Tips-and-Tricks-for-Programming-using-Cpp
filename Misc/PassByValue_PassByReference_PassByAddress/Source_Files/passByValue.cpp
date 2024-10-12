#include "passByValue.h"

int passByValue::smallest_element(const std::vector<int> vec) {
	auto smallest_val = vec[0];
	for (auto x : vec)
		smallest_val = std::min(smallest_val, x);

	return smallest_val;
}
