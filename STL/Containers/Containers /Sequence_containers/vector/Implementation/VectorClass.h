#include <iostream>
#include <string>

template <typename T> class VectorClass {
private:
    int m_size;     // private member to keep track of the size of the vector
    int m_capacity; // private member to keep track of the capacity of the
                    // vector
    T* m_data; // private member to point to the underlying array of the vector

public:

    // Default constructor to initialise the vector with size 0 and capacity 2
    VectorClass() : m_size(0), m_capacity(2), m_data(new T[m_capacity]) {}

    // Destructor to deallocate storage allocated by dynamic allocation to
    // prevent memory leak
    ~VectorClass() { delete[] m_data; }

    // Constructor with one argument to initialise the vector with a given size
    VectorClass(int size)
        : m_size(size), m_capacity(2 * size), m_data(new T[m_capacity]) {}

    // Copy constructor to handle object initialisation and copying
    VectorClass(const VectorClass& other)
        : m_size(other.m_size), m_capacity(other.m_capacity),
        m_data(new T[m_capacity]) {
        for (int i = 0; i < m_size; i++)
            m_data[i] = other.m_data[i];
    }

    // Function to increase capacity of the vector to a specified amount
    void reserve(int newCapacity) {
        T* newData = new T[newCapacity];
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

    // Operator[] overloading to allow accessing elements in the vector using
    // array notation
    T& operator[](int index) { return m_data[index]; }

    // Const version of operator[] overloading to allow accessing elements in
    // the vector using array notation
    const T& operator[](int index) const { return m_data[index]; }

    // Function to get the current size of the vector
    int size() const { return m_size; }

    // Function to check whether the vector is empty
    bool empty() const { return m_size == 0; }

    // Function to add an element at any index in the vector
    void insertAt(const T& val, int index) {
        if (index < 0 || index > m_size)
            return;

        if (m_size >= m_capacity)
            reserve(m_capacity * 2);

        for (int i = m_size - 1; i >= index; i--)
            m_data[i + 1] = m_data[i];

        m_data[index] = val;
        m_size++;
    }
};
