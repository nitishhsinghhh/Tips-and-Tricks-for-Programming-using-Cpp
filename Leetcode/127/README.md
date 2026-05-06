# 127. Word Ladder

## Problem Description

A transformation sequence from `beginWord` to `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

1. Every adjacent pair of words differs by a single letter.
2. Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
3  `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return the **number of words** in the **shortest transformation sequence** from `beginWord` to `endWord`, or `0` if no such sequence exists.

---

## Strategy: Breadth-First Search (BFS)

Since we are looking for the **shortest** transformation sequence, **Breadth-First Search (BFS)** is the ideal algorithm. BFS explores the graph layer by layer, guaranteeing that the first time we reach the `endWord`, we have found the shortest path.

### Key Conceptual Steps

1. **Graph Representation:** We treat each word as a node in a graph. An edge exists between two nodes if the words differ by exactly one letter.
2. **Preprocessing:** Iterating through the `wordList` for every word to check if it differs by one letter is inefficient ($O(N \cdot L)$). Instead, we use a "wildcard" approach (e.g., "hit" -> "\*it", "h\*t", "hi\*"). This allows us to group words that share the same intermediate pattern.
3. **Traversal:** * Use a queue to store `(current_word, current_level)`.
    * Use a `set` for the `wordList` for $O(1)$ lookups.
    * Use a `visited` set to ensure we don't process the same word twice, preventing infinite loops.

---

## Implementation (Python)

```python
from collections import deque, defaultdict

def ladderLength(beginWord, endWord, wordList):
    if endWord not in wordList:
        return 0
    
    # Preprocess words into generic patterns
    # e.g., "hot" -> ["*ot", "h*t", "ho*"]
    all_patterns = defaultdict(list)
    for word in wordList:
        for i in range(len(word)):
            pattern = word[:i] + "*" + word[i+1:]
            all_patterns[pattern].append(word)
            
    # BFS Setup
    queue = deque([(beginWord, 1)])
    visited = {beginWord}
    
    while queue:
        current_word, level = queue.popleft()
        
        # Try all patterns for the current word
        for i in range(len(current_word)):
            pattern = current_word[:i] + "*" + current_word[i+1:]
            
            for neighbor in all_patterns[pattern]:
                if neighbor == endWord:
                    return level + 1
                
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, level + 1))
            
            # Optimization: Clear pattern to avoid re-processing
            all_patterns[pattern] = []
            
    return 0
```
