// append_range (C++23)

#include <algorithm>
#include <cassert>
#include <vector>
#include <list>
#include <iostream>
 
int main() {
    auto head = std::vector{1, 2, 3, 4};
    const auto tail = std::list{-5, -6, -7};
#ifdef __cpp_lib_containers_ranges
    head.append_range(tail);
#else
    head.insert(head.end(), tail.cbegin(), tail.cend());
#endif
    assert(std::ranges::equal(head, std::vector{1, 2, 3, 4, -5, -6, -7}));
    
    for (const auto& elem : head)
        std::cout << elem << " ";
}

// 1 2 3 4 -5 -6 -7
