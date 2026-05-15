/**
 * @file arrangement_permutation.cpp
 * @author Nitish Singh
 * @brief Brute-force permutation solver with positional constraints.
 * @version 0.1
 * @date 2026-05-15
 * * @copyright Copyright (c) 2016-2026
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief Validates the seating arrangement based on specific social constraints.
 * * This function implements a constraint-check for a seating problem. 
 * The current business logic dictates that the character 'G' (Girl) 
 * cannot occupy the middle index of the arrangement.
 * * @param arrangement A vector of strings representing the sequence of people.
 * @return true If the arrangement satisfies the middle-bench constraint.
 * @return false If the arrangement violates the constraint (G is at index 1).
 */
bool isValid(const vector<string>& arrangement) {
    return arrangement[1] != "G";
}

/**
 * @brief Main entry point for the arrangement solver.
 * * Utilizes the STL next_permutation to generate the state space and
 * filters valid states into a collection for output.
 * * @return int Standard exit code (0 for success).
 */
int main() {
    vector<string> people = {"B1", "B2", "G"};
    vector<vector<string>> validArrangements;

    sort(people.begin(), people.end());
    
    do {
        if (isValid(people)) 
            validArrangements.push_back(people);

    } while (next_permutation(people.begin(), people.end()));

    // Output valid arrangements to standard console
    for (const auto& arrangement : validArrangements) {
        for (const auto& person : arrangement) 
            cout << person << " ";
            
        cout << endl;
    }

    return 0;
}