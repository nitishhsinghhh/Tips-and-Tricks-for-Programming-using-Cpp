#include <iostream>
#include <vector>
#include <random>

/**
 * @brief Shuffles the elements of an integer array using the Fisher-Yates algorithm.
 * 
 * This function implements the Fisher-Yates shuffle (also known as the Knuth shuffle)
 * to generate a uniform random permutation of the input array.
 * 
 * @param arr A reference to the vector of integers to be shuffled.
 * 
 * @details
 * The algorithm iterates from the last element to the second, generating a random index
 * from the subarray [0, i] and swapping the current element with the element at that index.
 * It uses a Mersenne Twister (mt19937) for high-quality randomness, seeded by random_device.
 */

void shuffle(std::vector<int>& arr) {
    std::random_device rd;              ///< Random device to seed the generator
    std::mt19937 gen(rd());             ///< Mersenne Twister pseudo-random generator

    for (int i = arr.size() - 1; i > 0; i--) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);         ///< Generate a random index in range [0, i]
        std::swap(arr[i], arr[j]);      ///< Swap current element with randomly chosen element
    }
}

/**
 * @brief Main function to demonstrate the shuffle.
 * 
 * Initializes a vector of integers and calls the shuffle function.
 * Outputs the shuffled result to the console.
 * 
 * @return int Exit status code (0 for success).
 */

int main() {
    std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; ///< Input array
    shuffle(arr);

    std::cout << "Shuffled array: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
