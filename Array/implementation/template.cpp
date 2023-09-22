#include <iostream>
#include<string>
using namespace std;

template<typename T>

class Vector {
private:
	int m_size;
	int m_capacity;
	T *m_data;

public:
	Vector(): m_size(0), m_capacity(2), m_data(new T[m_capacity]) {}
	Vector(int size) : m_size(size), m_capacity(2 * size), m_data(new T[m_capacity]) {}
	Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[m_capacity]) {
		for (int i = 0; i < m_size; i++)
			m_data[i] = other.m_data[i];
	}
	~Vector() {
		delete[] m_data;
	}

	void reserve(int newCapacity) {
		T *newData = new T[newCapacity];
		for (int i = 0; i < m_size; i++)
			newData[i] = m_data[i];

		delete[] m_data;
		m_data = newData;
		m_capacity = newCapacity;
	}

	void push_back(const T& val) {
		if (m_size >= m_capacity)
			reserve(m_capacity * 2);

		m_data[m_size++] = val;			
	}

	void pop_back() {
		if (m_size > 0)
			m_size--;
	}

	T& operator[] (int index) {
		return m_data[index];
	}

	const T& operator[](int index) const {
		return m_data[index];
	}

	int size() const {
		return m_size;
	}

	bool empty() const {
		return m_size == 0;
	}

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
	Vector<string> vec;
	vec.push_back("A");
	vec.push_back("B");
	vec.push_back("C");

	cout<< "The vector at index 2 is: " << vec[2] << endl;

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	vec.insertAt("AA", 2);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	vec.pop_back();

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	system("pause");
}
