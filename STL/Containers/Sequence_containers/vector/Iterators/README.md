# Understanding Iterators

Iterators are a fundamental concept in the C++ Standard Template Library (STL), and the [vector](https://en.cppreference.com/w/cpp/container/vector) container provides several types of iterators to traverse and manipulate its elements.

## Iterators

- **begin/ cbegin** (C++11): Returns an iterator to the beginning (public member function)
- **end / cend** (C++11): Returns an iterator to the end (public member function)
- **rbegin/ crbegin** (C++11): Returns a reverse iterator to the beginning (public member function)
- **rend / crend** (C++11): Returns a reverse iterator to the end (public member function)

The `begin()` and `end()` iterators provide access to the first and last elements of the vector, respectively.

The `rbegin()` and `rend()` iterators provide reverse access to the elements of the vector, enabling programmers to traverse the vector from end to start.
