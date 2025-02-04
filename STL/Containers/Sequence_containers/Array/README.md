# Array

Defined in header ```<array>```
```cpp
template<
    class T,
    std::size_t N
> struct array;
(since C++11)
```
std::array is a container that encapsulates fixed size arrays.

This container is an aggregate type with the same semantics as a struct holding a C-style array T[N] as its only non-static data member. Unlike a C-style array, it doesn't decay to T* automatically. As an aggregate type, it can be initialized with aggregate-initialization given at most N initializers that are convertible to T: 
```std::array<int, 3> a = {1, 2, 3};```

The struct combines the performance and accessibility of a C-style array with the benefits of a standard container, such as knowing its own size, supporting assignment, random access iterators, etc.

std::array satisfies the requirements of Container and ReversibleContainer except that default-constructed array is not empty and that the complexity of swapping is linear, ```satisfies the requirements of ContiguousContainer,(since C++17)``` and partially satisfies the requirements of SequenceContainer.

There is a special case for a zero-length array (N == 0). In that case, ```array.begin() == array.end()```, which is some unique value. The effect of calling ```front()``` or ```back()``` on a zero-sized array is undefined.

An array can also be used as a tuple of N elements of the same type.

## Iterator invalidation
As a rule, iterators to an array are never invalidated throughout the lifetime of the array. One should take note, however, that during ```swap```, the iterator will continue to point to the same array element, and will thus change its value.

# Template parameters
T - element type Must be ```MoveConstructible``` and ```MoveAssignable```. <br>
N - the number of elements in the array or 0.

# Member types

| Member types       | Definition                                             |
|--------------------|--------------------------------------------------------|
| value_type         | T                                                      |
| size_type          | std::size_t                                             |
| difference_type    | std::ptrdiff_t                                          |
| reference          | value_type&                                            |
| const_reference    | const value_type&                                      |
| pointer            | value_type*                                            |
| const_pointer      | const value_type*                                      |
| iterator           | LegacyRandomAccessIterator and LegacyContiguousIterator to value_type (until C++17) <br> LegacyRandomAccessIterator and LegacyContiguousIterator that is a LiteralType to value_type (since C++17, until C++20) <br> LegacyRandomAccessIterator, contiguous_iterator, and ConstexprIterator to value_type (since C++20) |
| const_iterator     | LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type (until C++17) <br> LegacyRandomAccessIterator and LegacyContiguousIterator that is a LiteralType to const value_type (since C++17, until C++20) <br> LegacyRandomAccessIterator, contiguous_iterator, and ConstexprIterator to const value_type (since C++20) |
| reverse_iterator   | std::reverse_iterator <iterator> |
| const_reverse_iterator | std::reverse_iterator<const_iterator>                 |


# Member functions
## Implicitly-defined member functions
| Member Function | Description |
|-----------------|-------------|
| (constructor)  (implicitly declared) |  initializes the array following the rules of aggregate initialization (note that default initialization may result in indeterminate values for non-class T) (public member function) |
| (destructor) (implicitly declared) | destroys every element of the array (public member function) |
| operator= (implicitly declared) | overwrites every element of the array with the corresponding element of another array (public member function) |


# Element access
| Member Function | Description |
|-----------------|-------------|
| at              | access specified element with bounds checking |
| operator[]      | access specified element |
| front           | access the first element |
| back            | access the last element |
| data            | direct access to the underlying contiguous storage |


# Iterators
| Member Function | Description |
|-----------------|-------------|
| begin           | returns an iterator to the beginning |
| cbegin          | returns a const iterator to the beginning |
| end             | returns an iterator to the end |
| cend            | returns a const iterator to the end |
| rbegin          | returns a reverse iterator to the beginning |
| crbegin         | returns a const reverse iterator to the beginning |
| rend            | returns a reverse iterator to the end |
| crend           | returns a const reverse iterator to the end |


# Capacity
| Member Function | Description |
|-----------------|-------------|
| empty           | checks whether the container is empty |
| size            | returns the number of elements |
| max_size        | returns the maximum possible number of elements |


# Operations
| Member Function | Description |
|-----------------|-------------|
| fill            | fill the container with specified value |
| swap            | swaps the contents |


# Non-member functions
| Function       | Description |
|----------------|-------------|
| operator==(C++11)     | lexicographically compares the values of two arrays (function template) |
| operator!=(C++11)(removed in C++20)     | lexicographically compares the values of two arrays (function template) |
| operator<(C++11)(removed in C++20)     | lexicographically compares the values of two arrays (function template) |
| operator<=(C++11)(removed in C++20)     | lexicographically compares the values of two arrays (function template) |
| operator>(C++11)(removed in C++20)      | lexicographically compares the values of two arrays (function template) |
| operator>=(C++11)(removed in C++20)     | lexicographically compares the values of two arrays (function template) |
| operator<=>(C++20)    | compares the values of two arrays (C++20) |
| get(C++11)            | accesses an element of an array (function template) |
| std::swap(C++11)      | specializes the std::swap algorithm for arrays (function template) |
| to_array(C++20)       | creates a std::array object from a built-in array (function template) |


# Helper classes
| C++11 Feature                    | Description                              | Type                                |
|----------------------------------|------------------------------------------|-------------------------------------|
| std::tuple_size<std::array>      | Obtains the size of an array            | Class Template Specialization       |
| std::tuple_element<std::array>   | Obtains the type of the elements of array | Class Template Specialization     |


# Example 
```cpp
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
 
int main() {
    // Construction uses aggregate initialization
    std::array<int, 3> a1{{1, 2, 3}}; // Double-braces required in C++11 prior to
                                      // the CWG 1270 revision (not needed in C++11
                                      // after the revision and in C++14 and beyond)
 
    std::array<int, 3> a2 = {1, 2, 3}; // Double braces never required after =
 
    // Container operations are supported
    std::sort(a1.begin(), a1.end());
    std::ranges::reverse_copy(a2, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
 
    // Ranged for loop is supported
    std::array<std::string, 2> a3{"E", "\u018E"};
    for (const auto& s : a3)
        std::cout << s << ' ';
    std::cout << '\n';
 
    // Deduction guide for array creation (since C++17)
    [[maybe_unused]] std::array a4{3.0, 1.0, 4.0}; // std::array<double, 3>
 
    // Behavior of unspecified elements is the same as with built-in arrays
    [[maybe_unused]] std::array<int, 2> a5; // No list init, a5[0] and a5[1]
                                            // are default initialized
    [[maybe_unused]] std::array<int, 2> a6{}; // List init, both elements are value
                                              // initialized, a6[0] = a6[1] = 0
    [[maybe_unused]] std::array<int, 2> a7{1}; // List init, unspecified element is value
                                               // initialized, a7[0] = 1, a7[1] = 0
}
```

### Output:

```
3 2 1
E Ǝ
```
