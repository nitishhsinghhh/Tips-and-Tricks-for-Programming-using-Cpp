#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using std::string;

void reverseWord(char* arr, int start, int end) {
    while (start < end) {
        // Manual swap without std::swap
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/**
 * @brief Reverses each word in a sentence stored in a char array.
 *
 * Example: Input  -> "My name is Nitish"
 *          Output -> "yM eman si hsitiN"
 */
void reverseEachWord_Update(char* str) {
    int i = 0, start = 0;

    while (str[i] != '\0') {
        // When space or end of string is found, reverse the word
        if (str[i] == ' ' || str[i + 1] == '\0') {
            int end = (str[i] == ' ') ? i - 1 : i;
            reverseWord(str, start, end);
            start = i + 1;
        }
        i++;
    }
}

string reverseEachWord(const string& input) {
    std::stringstream ss(input);
    string word, result;

    while (ss >> word) {
        reverse(word.begin(), word.end());
        result += word + ' ';
    }

    // Remove trailing space
    if (!result.empty()) 
        result.pop_back();

    return result;
}

string swapWords(string& s) {
    int size = s.size();
    for (int i = 0; i < size / 2; i++) {
        std::swap(s[i], s[size - i - 1]);
    }
    return s;
}

string swapWordByWord(string& s) {
    string res = "";
    string tmp = "";
    for (char c : s) {
        if (c != ' ') {
            tmp += c;
        } else {
            res += swapWords(tmp);
            res += ' ';
            tmp = "";
        }
    }
    res += swapWords(tmp);
    return res;
}

int main() {
    // --- First Approach (std::string + stringstream) ---
    string sentenceStr = "My name is Nitish";
    string reversed = reverseEachWord(sentenceStr);
    std::cout << "Method 1: " << reversed << std::endl; // Output: yM eman si hsitiN


    // --- Second Approach (In-place char array modification) ---
    char sentenceArr[] = "My name is Nitish";
    reverseEachWord_Update(sentenceArr);
    std::cout << "Method 2: " << sentenceArr << std::endl; // Output: yM eman si hsitiN


    // --- Third Approach (Using your custom swapWordByWord string logic) ---
    string sentenceStr3 = "My name is Nitish";
     
    string reversed3 = swapWordByWord(sentenceStr3);
    
    std::cout << "Method 3: " << reversed3 << std::endl; // Output: yM eman si hsitiN

    return 0;
}