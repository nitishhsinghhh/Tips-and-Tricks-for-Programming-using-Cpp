# Robot Collisions Problem Solution

## [Problem Statement](https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2024-07-13)

The problem "Robot Collisions" involves a set of robots positioned on a line. Each robot has a unique position, a health value, and a direction of movement (either left 'L' or right 'R'). The robots start moving simultaneously at the same speed. When two robots collide, the robot with lower health is removed from the line, and the health of the surviving robot decreases by one. If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions in the same order they were given. If no robots survive, return an empty array.

## Example Scenarios

### Example 1

**Input:**
- Positions: [5, 4, 3, 2, 1]
- Healths: [2, 17, 9, 15, 10]
- Directions: "RRRRR"

**Output:**
- [2, 17, 9, 15, 10]

**Explanation:**
No collision occurs since all robots are moving in the same direction. Therefore, the health of the robots remains unchanged.

### Example 2

**Input:**
- Positions: [3, 5, 2, 6]
- Healths: [10, 10, 15, 12]
- Directions: "RLRL"

**Output:**
- [14]

**Explanation:**
- Robot 1 (R) collides with Robot 2 (L). Both have the same health and are removed.
- Robot 3 (R) collides with Robot 4 (L). Robot 4 is removed, and Robot 3's health is reduced to 14.

### Example 3

**Input:**
- Positions: [1, 2, 5, 6]
- Healths: [10, 10, 11, 11]
- Directions: "RLRL"

**Output:**
- []

**Explanation:**
- Robot 1 (R) collides with Robot 2 (L). Both have the same health and are removed.
- Robot 3 (R) collides with Robot 4 (L). Both have the same health and are removed.

## Constraints

- 1 <= positions.length == healths.length == directions.length == n <= 105
- 1 <= positions[i], healths[i] <= 109
- directions[i] == 'L' or 'R'
- All values in positions are distinct

## Solution Approach

The solution approach involves using a stack to handle the collisions and a vector to store the indices of robots sorted by their positions. Here's a step-by-step breakdown of the solution:

1. **Initialization**:
   - Create a vector `indices` to store the indices of the robots.
   - Use `std::iota` to initialize the `indices` vector with values from 0 to n-1.
   - Sort the `indices` vector based on the positions of the robots.

2. **Collision Handling**:
   - Iterate through the sorted indices and process each robot.
   - Use a stack to manage the robots moving to the right ('R').
   - For each left-moving robot ('L'), check for collisions with the right-moving robots on the stack.
   - Resolve collisions by comparing the health values:
     - The robot with lower health is destroyed.
     - The health of the surviving robot is decreased by one.
     - If both robots have the same health, both are destroyed.

3. **Collecting Results**:
   - After processing all robots, collect the health values of the surviving robots in the original order.

Here is the complete C++ code for the solution:

```cpp
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>  // For std::iota

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n), result;
        stack<int> stack;

        // Initialize the indices array to [0, 1, 2, ..., n-1]
        std::iota(indices.begin(), indices.end(), 0);

        // Sort the indices array based on the positions of the robots
        sort(indices.begin(), indices.end(), [&](int lhs, int rhs) { 
            return positions[lhs] < positions[rhs]; 
        });

        // Process each robot in the order of their positions
        for (int currentIndex : indices) {
            if (directions[currentIndex] == 'R') 
                stack.push(currentIndex);
            else {
                while (!stack.empty() && healths[currentIndex] > 0) {
                    int topIndex = stack.top();
                    stack.pop();

                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }
        
        for (int index = 0; index < n; ++index)
            if (healths[index] > 0)
                result.push_back(healths[index]);

        return result;
    }
};
```

## Conclusion
The robot collisions problem is an interesting challenge that involves handling simultaneous movements and resolving collisions based on health values. The solution employs a stack to manage the collisions effectively and a vector to keep track of robot indices sorted by their positions. This ensures that the robots are processed in the correct order and the collisions are resolved accurately. By following this approach, you can determine the health of the surviving robots after all collisions have occurred.
