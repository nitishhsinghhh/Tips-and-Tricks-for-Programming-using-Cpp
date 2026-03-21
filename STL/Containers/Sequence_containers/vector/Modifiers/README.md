# Modifying the Vector

The [vector](https://en.cppreference.com/w/cpp/container/vector) container in C++ provides a rich set of modifiers to add, remove, and modify elements. Here are some of the key functions available. Please click the [link](https://en.cppreference.com/w/cpp/container/vector) for more information.

## Modifiers

- **clear**: Clears the contents (public member function)
- **insert**: Inserts elements (public member function)
- **insert_range** (C++23): Inserts a range of elements (public member function)
- **emplace** (C++11): Constructs element in-place (public member function)
- **erase**: Erases elements (public member function)
- **push_back**: Adds an element to the end (public member function)
- **emplace_back** (C++11): Constructs an element in-place at the end (public member function)
- **append_range** (C++23): Adds a range of elements to the end (public member function)
- **pop_back**: Removes the last element (public member function)
- **resize**: Changes the number of elements stored (public member function)
- **swap**: Swaps the contents (public member function)

For example, using `emplace()` and `emplace_back()` can be more efficient than using `insert()` and `push_back()` when constructing new elements from scratch. Similarly, using `erase()` and `clear()` can help free up memory and optimize performance when removing elements from the vector.
