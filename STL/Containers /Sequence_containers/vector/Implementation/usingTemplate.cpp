#include <iostream>
#include<string>

template<typename T>
class Vector {
private:
	int m_size; // private member to keep track of the size of the vector
	int m_capacity; // private member to keep track of the capacity of the vector
	T *m_data; // private member to point to the underlying array of the vector

public:
	// Default constructor to initialise the vector with size 0 and capacity 2
	Vector() : m_size(0), m_capacity(2), m_data(new T[m_capacity]) {}
	// Constructor with one argument to initialise the vector with a given size
	Vector(int size) : m_size(size), m_capacity(2 * size), m_data(new T[m_capacity]) {}
	// Copy constructor to handle object initialisation and copying
	Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[m_capacity]) {
		for (int i = 0; i < m_size; i++)
			m_data[i] = other.m_data[i];
	}

	// Destructor to deallocate storage allocated by dynamic allocation to prevent memory leak
	~Vector() {
		delete[] m_data;
	}

	// Function to increase capacity of the vector to a specified amount
	void reserve(int newCapacity) {
		T *newData = new T[newCapacity];
		for (int i = 0; i < m_size; i++)
			newData[i] = m_data[i];

		delete[] m_data;
		m_data = newData;
		m_capacity = newCapacity;
	}

	// Function to add an element to the end of the vector
	void push_back(const T& val) {
		if (m_size >= m_capacity)
			reserve(m_capacity * 2);
		m_data[m_size++] = val;
	}

	// Function to delete the last element from the vector
	void pop_back() {
		if (m_size > 0)
			m_size--;
	}

	// Operator[] overloading to allow accessing elements in the vector using array notation
	T& operator[] (int index) {
		return m_data[index];
	}

	// Const version of operator[] overloading to allow accessing elements in the vector using array notation
	const T& operator[](int index) const {
		return m_data[index];
	}

	// Function to get the current size of the vector
	int size() const {
		return m_size;
	}

	// Function to check whether the vector is empty
	bool empty() const {
		return m_size == 0;
	}

	// Function to add an element at any index in the vector
	void insertAt(const T& val, int index) {
		if (index < 0 || index > m_size) return;

		if (m_size >= m_capacity)
			reserve(m_capacity * 2);

		for (int i = m_size - 1; i >= index; i--)
			m_data[i + 1] = m_data[i];

		m_data[index] = val;
		m_size++;
	}
};

int main() {
	// Creating a Vector object of type string
	Vector<std::string> vec;
	// Adding three elements to the vector using push_back()
	vec.push_back("A");
	vec.push_back("B");
	vec.push_back("C");

	// Printing the element at index 2 using operator[]
	std::cout << "The vector at index 2 is: " << vec[2] << std::endl;

	// Printing all the elements of the vector using a for loop and operator[]
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	// Inserting a new element at index 2 using insertAt() and printing the updated elements of the vector
	vec.insertAt("AA", 2);
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	// Removing the last element using pop_back() and printing the updated elements of the vector
	vec.pop_back();
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	// Pausing the console
	system("pause");
}

/*
The vector at index 2 is: C
A B C
A B AA C
A B AA
Press any key to continue . . .

*/
