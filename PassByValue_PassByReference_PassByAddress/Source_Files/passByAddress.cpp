#include "passByAddress.h"

int passByAddress::smallest_element(const std::vector<int>* vec) {
    if (vec->empty()) return INT_MAX; // Handle empty vector case
    auto smallest_val = (*vec)[0];
    for (auto x : *vec) {
        smallest_val = std::min(smallest_val, x);
    }
    return smallest_val;
}
