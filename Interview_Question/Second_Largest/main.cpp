#include <iostream>
#include <vector>
#include <limits>

int findSecondLargest(const std::vector<int>& nums)
{
    int largest = std::numeric_limits<int>::min();
    int secondLargest = std::numeric_limits<int>::min();

    for (int num : nums)
    {
        if (num > largest)
        {
            secondLargest = largest;
            largest = num;
        }
        else if (num > secondLargest && num != largest)
        {
            secondLargest = num;
        }
    }

    return secondLargest;
}

int main()
{
    std::vector<int> nums = {10, 5, 20, 8, 15};

    std::cout << findSecondLargest(nums) << std::endl; // Output: 15

    return 0;
}