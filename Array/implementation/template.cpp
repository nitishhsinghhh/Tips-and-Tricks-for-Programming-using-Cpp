#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
	int m_size;
	int m_capacity;
	T* m_data;

public:
	Vector() : m_size(0), m_capacity(2), m_data(new T[m_capacity]) {}
	Vector(int size) : m_size(size), m_capacity(size * 2), m_data(new T[m_capacity]) {}
	Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[m_capacity]) {
		for (int i = 0; i < m_size; i++) 
			m_data[i] = other.m_data[i];
	}

	~Vector() {
		delete[] m_data;
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

	void reserve(int newCapacity) {
		T* newData = new T[newCapacity];
		for (int i = 0; i < m_size; i++) 
			newData[i] = m_data[i];

		delete[] m_data;
		m_data = newData;
		m_capacity = newCapacity;
	}

	T& operator[](int index) {
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
};

int main() {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << " ";
	cout << endl;

	v.pop_back();

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}
