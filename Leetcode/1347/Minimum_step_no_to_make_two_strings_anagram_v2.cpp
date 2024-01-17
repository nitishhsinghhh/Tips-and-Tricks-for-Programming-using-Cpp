
int minSteps(const std::string& s, const std::string& t) {
        // Create a vector to store the frequency difference of characters
        std::vector<int> freqDifference(26, 0);

        // Count the frequency of characters in string s
        for (char ch : s) {
            freqDifference[ch - 'a']++;
        }

        // Subtract the frequency of characters in string t
        for (char ch : t) {
            freqDifference[ch - 'a']--;
        }

        // Initialize the result variable
        int res = 0;

        // Iterate over the frequency difference vector
        for (int value : freqDifference) {
            // Add the absolute value of the frequency difference to the result
            res += abs(value);
        }

        // Return the final result, divided by 2 as each difference contributes twice
        return res / 2;
    }
