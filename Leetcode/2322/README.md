# Problem Explanation: Leetcode 2322 - Minimum Score After Removals on a Tree

You're given:
- A tree with n nodes labeled from 0 to n-1.
- An array nums where nums[i] is the value of node i.
- An array edges representing the connections between nodes.

## Goal:
Remove two distinct edges from the tree to split it into three connected components. For each component:
- Compute the XOR of all node values.
- Calculate the score as the difference between the maximum XOR and minimum XOR among the three components.
- Return the minimum score possible across all valid pairs of edge removals.

## Topics
- Array
- Bit Manipulation
- Tree
- Depth-First Search

## Key Observations:
- A tree with n nodes has n-1 edges and is acyclic and connected.
- Removing two edges will always split the tree into three components.
- The challenge is to efficiently explore all valid edge removal pairs and compute the XORs.

## Code Explanation
The provided C++ solution uses DFS and backtracking to simulate edge removals and compute XORs:

### Data Members:
```cpp
unordered_set<int> v[1002]; // Adjacency list
bool vis[1002];             // Visited array
int res = INT_MAX;          // Minimum score
int comp_1, comp_2, comp_3; // XORs of the 3 components
```

## Solution 
```cpp
/**
 * @class Solution
 * @brief Solves the problem of minimizing the score after removing two edges from a tree.
 */
class Solution {
public:
    unordered_set<int> v[1002]; ///< Adjacency list for the graph
    bool vis[1002];             ///< Visited array for DFS traversal

    int res = INT_MAX;          ///< Stores the minimum score
    int comp_1, comp_2, comp_3; ///< Stores XOR values of the three components

    /**
     * @brief Performs DFS to compute XOR of a connected component.
     * @param i Current node index
     * @param a Vector of node values
     * @return XOR of the component
     */
    int dfs(int i, vector<int>& a) {
        int curr = a[i];
        vis[i] = true;

        for (auto x : v[i]) {
            if (!vis[x]) {
                curr ^= dfs(x, a);
            }
        }

        return curr;
    }

    /**
     * @brief Performs DFS to compute XORs of the remaining two components and updates the result.
     * @param i Current node index
     * @param j XOR of the remaining nodes
     * @param a Vector of node values
     * @return XOR of the current component
     */
    int dfs1(int i, int j, vector<int>& a) {
        vis[i] = true;
        int curr = a[i];

        for (auto x : v[i]) {
            if (!vis[x]) {
                int res1 = dfs1(x, j, a);

                comp_2 = res1;
                comp_3 = j ^ res1;

                res = min(res, max({comp_1, comp_2, comp_3}) - min({comp_1, comp_2, comp_3}));

                curr ^= res1;
            }
        }

        return curr;
    }

    /**
     * @brief Computes the minimum score after removing two edges from the tree.
     * @param nums Vector of node values
     * @param edges Vector of edges in the tree
     * @return Minimum score
     */
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        for (auto& x : edges) {
            v[x[0]].insert(x[1]);
            v[x[1]].insert(x[0]);
        }

        int val = 0;
        for (auto x : nums) {
            val ^= x;
        }

        res = INT_MAX;

        for (auto& x : edges) {
            // Remove one edge
            v[x[0]].erase(x[1]);
            v[x[1]].erase(x[0]);

            fill(begin(vis), end(vis), false);
            comp_1 = dfs(0, nums);

            int pos = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (!vis[i]) {
                    pos = i;
                    dfs1(i, comp_1 ^ val, nums);
                }
            }

            fill(begin(vis), end(vis), false);
            comp_1 = dfs(pos, nums);

            for (int i = 0; i < nums.size(); i++)
                if (!vis[i])  
                    dfs1(i, comp_1 ^ val, nums); 

            v[x[0]].insert(x[1]);
            v[x[1]].insert(x[0]);
        }

        return res;
    }
};

/*
+--------------------------------------+
|              Solution               |
+--------------------------------------+
| - unordered_set<int> v[1002]        |
| - bool vis[1002]                    |
| - int res                           |
| - int comp_1                        |
| - int comp_2                        |
| - int comp_3                        |
+--------------------------------------+
| + int dfs(int i, vector<int>& a)    |
| + int dfs1(int i, int j, vector<int>& a) |
| + int minimumScore(vector<int>& nums, vector<vector<int>>& edges) |
+--------------------------------------+
*/
```
