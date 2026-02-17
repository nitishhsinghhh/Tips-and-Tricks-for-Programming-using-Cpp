#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

class FindSumPairs {
private:
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> freqMap;

public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freqMap[num]++;
        }
    }

    void add(int index, int val) {
        if (index >= 0 && index < nums2.size()) {
            int oldVal = nums2[index];
            freqMap[oldVal]--;
            nums2[index] += val;
            freqMap[nums2[index]]++;
        }
    }

    int count(int tot) {
        int res = 0;
        for (int num : nums1) {
            int complement = tot - num;
            if (freqMap.count(complement)) {
                res += freqMap[complement];
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {3, 4, 5};

    FindSumPairs obj(nums1, nums2);

    // Test 1
    assert(obj.count(6) == 3); // (1+5, 2+4, 3+3)

    // Test 2
    obj.add(1, 1); // nums2 becomes {3, 5, 5}
    assert(obj.count(6) == 3); // (1+5 x2, 3+3)

    // Test 3
    obj.add(2, -2); // nums2 becomes {3, 5, 3}
    assert(obj.count(5) == 2); // (2+3, 3+2)

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}