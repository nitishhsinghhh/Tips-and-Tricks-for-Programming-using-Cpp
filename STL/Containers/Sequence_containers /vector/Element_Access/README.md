## Element Access

Accessing and modifying elements within the vector container is one of its key strengths.Here are several methods that can be used to access and manipulate elements based on their positions within the vector. 

- **at**: access specified element with bounds checking (public member function)
- **operator[]**: access specified element (public member function)
- **front**: access the first element (public member function)
- **back**: access the last element (public member function)
- **data**: direct access to the underlying contiguous storage (public member function)

All of these methods provide convenient ways to retrieve and modify elements based on their positions in the vector. For example, you can use the reference operator to assign a new value to an element in the vector:

```cpp
std::vector<int> vec {1, 2, 3, 4, 5};
vec[2] = 10; // Assigns the value 10 to the third element
```

Similarly, you can use the at() method to access an element and perform bounds checking:

```cpp
std::vector<int> vec {1, 2, 3, 4, 5};
try {
    int value = vec.at(10); // Throws an out_of_range exception
} catch (const std::out_of_range& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```
