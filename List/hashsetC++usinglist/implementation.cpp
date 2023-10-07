#include "pch.h"
#include<iostream>
#include<list>
	
template <typename T>
class HashSet {
private:
	static const int size = 1000;
	std::list<T> table[size];

	int hash(T key) {
		return std::hash<T>{}(key) % size;
	}
public:
	void insert(T key) {
		int index = hash(key);
		table[index].push_back(key);
	}

	void remove(T key) {
		int index = hash(key);
		table[index].remove(key);
	}

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
Output:
HashSet contains 10: 1
HashSet contains 99: 0
HashSet contains 'banana': 1
HashSet contains 'grape': 0
*/
