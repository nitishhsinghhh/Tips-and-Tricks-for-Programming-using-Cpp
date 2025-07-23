#include<iostream>
#include<list>

/**
 * @brief A simple HashSet implementation using separate chaining for collision resolution.
 * 
 * @tparam T The type of elements stored in the set. Requires T to be hashable and comparable.
 */
template <typename T>
class HashSet {
private:
	/// @brief Number of buckets in the hash table.
	static const int size = 1000;

	/// @brief The hash table represented as an array of linked lists (buckets).
	std::list<T> table[size];

	/**
	 * @brief Computes the hash index for a given key.
	 * 
	 * @param key The key to hash.
	 * @return int The index in the hash table.
	 */
	int hash(T key) {
		return std::hash<T>{}(key) % size;
	}
public:
	/**
	 * @brief Inserts a key into the HashSet.
	 * 
	 * @param key The key to insert.
	 */
	void insert(T key) {
		int index = hash(key);
		table[index].push_back(key);
	}

	/**
	 * @brief Removes a key from the HashSet.
	 * 
	 * @param key The key to remove.
	 */
	void remove(T key) {
		int index = hash(key);
		table[index].remove(key);
	}

	/**
	 * @brief Checks if the HashSet contains a key.
	 * 
	 * @param key The key to check.
	 * @return true If the key is present.
	 * @return false If the key is not present.
	 */
	bool contains(T key) {
		int index = hash(key);
		for (const T& val : table[index]) {
			if (val == key) {
				return true;
			}
		}
		return false;
	}
};

/**
 * @brief Demonstrates the usage of the HashSet with int and std::string types.
 */
int main() {
	HashSet<int> intHashSet;
	intHashSet.insert(42);
	intHashSet.insert(10);
	intHashSet.insert(7);
	std::cout << "HashSet contains 10: " << intHashSet.contains(10) << std::endl;
	std::cout << "HashSet contains 99: " << intHashSet.contains(99) << std::endl;

	HashSet<std::string> stringHashSet;
	stringHashSet.insert("apple");
	stringHashSet.insert("banana");
	stringHashSet.insert("cherry");
	std::cout << "HashSet contains 'banana': " << stringHashSet.contains("banana") << std::endl;
	std::cout << "HashSet contains 'grape': " << stringHashSet.contains("grape") << std::endl;
	return 0;
}

/*
Expected Output:
HashSet contains 10: 1
HashSet contains 99: 0
HashSet contains 'banana': 1
HashSet contains 'grape': 0
*/
