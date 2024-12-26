#include "passByAddress.h"

using std::vector;
using std::min;

int passByAddress::smallest_element(vector<int>* vec) {
    if (vec->empty()) return INT_MAX; // Handle empty vector case
    auto smallest_val = (*vec)[0];
    for (auto x : *vec) {
        smallest_val = min(smallest_val, x);
    }
    return smallest_val;
}
