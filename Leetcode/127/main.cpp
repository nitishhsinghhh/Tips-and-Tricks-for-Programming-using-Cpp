#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using std::string;
using std::vector;
using std::unordered_set;
using std::queue;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }

                dict.erase(word);
                for (size_t j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};

int main() {
    Solution sol;

    vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    int result1 = sol.ladderLength("hit", "cog", wordList1);
    std::cout << "Test 1 Result: " << result1 << " (Expected: 5)" << std::endl;

    vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
    int result2 = sol.ladderLength("hit", "cog", wordList2);
    std::cout << "Test 2 Result: " << result2 << " (Expected: 0)" << std::endl;

    return 0;
}