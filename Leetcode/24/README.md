## Leetcode 24: Swap Nodes in pairs

### Approach:
Here's a concise explanation of the approach:

1. **Base Case Handling:** 
   - If the list is empty or has only one node, return the head.

2. **Initialization:**
   - Set `newHead` to the second node, as it will become the new head after the first swap.
   - Use `current` to track the node being processed and `previous` to track the node before the current pair.

3. **Swapping Logic:**
   - Iterate through the list, swapping each pair of nodes:
     - Identify the two nodes to be swapped (`current` and `current->next`).
     - Adjust pointers to swap the nodes and maintain list connections.
     - Update `previous` to `current` and move `current` to the next pair.

4. **Return the New Head:**
   - Return `newHead` which points to the new head of the swapped list.

This method efficiently swaps adjacent nodes while preserving the overall structure of the linked list.
