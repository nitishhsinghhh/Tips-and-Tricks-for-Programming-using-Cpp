// insert_range (C++23)

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iterator>
#include <vector>
#include <list>
 
int main() {
    auto container = std::vector{1, 2, 3, 4};
    auto pos = std::next(container.begin(), 2);
    assert(*pos == 3);
    const auto rg = std::list{-1, -2, -3};
 
#ifdef __cpp_lib_containers_ranges
    container.insert_range(pos, rg);
#else
    container.insert(pos, rg.cbegin(), rg.cend());
    
#endif

    assert(std::ranges::equal(container, std::vector{1, 2, -1, -2, -3, 3, 4}));
    for (const auto& elem : container)
      std::cout << elem << " ";
}

// 1 2 -1 -2 -3 3 4
