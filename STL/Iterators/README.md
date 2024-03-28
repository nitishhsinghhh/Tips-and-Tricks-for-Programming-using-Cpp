# Iterators 
Iterators are a key component of the C++ Standard Template Library (STL) and serve as a unified way to access elements within various types of containers, such as vectors, lists, and arrays. They simplify the complexity of working with containers and promote code reusability.

In C++, iterators are categorized into five main types:
- input iterators,
- output iterators,
- forward iterators,
- bidirectional iterators, and
- random access iterators.

Each type of iterator has its own specific functionality and capabilities, providing a range of options for working with different types of containers. This article will cover the concept of iterators in C++98, how to effectively use them, and their role in streamlining container traversal.

In straightforward terms, an iterator is an object that enables us to access and modify elements within a container. It functions as a generalized pointer that moves through the elements of a container, providing a consistent way to access and modify these elements without directly interacting with the underlying container implementation.

Iterators are a foundational component of the C++ STL. They are used to point to the memory address of STL container classes and can be likened to pointers to some extent. Serving as a link between algorithms and STL containers, iterators facilitate the modification of data within the container, allowing iteration, access, assignment of values, and the application of various operators to achieve desired outcomes.

C++98 introduces various iterator types, each designed for specific purposes. Some of the commonly used iterator types in C++98 include:

1. **Input Iterator:** Enables read-only traversal in a forward direction.
2. **Output Iterator:** Facilitates write-only traversal in a forward direction.
3. **Forward Iterator:** Supports both read and write traversal in a forward direction.
4. **Bidirectional Iterator:** Allows for read and write traversal in both forward and backward directions.
5. **Random Access Iterator:** Provides read and write traversal with direct element access using operators such as +, -, +=, and -=.

Syntax of Defining Iterators:

The syntax for defining iterators in C++ is as follows:
```cpp
<Container_Type>::iterator;
<Container_Type>::const_iterator;
```

In the above syntax:
```Container_Type``` represents the type of container for which the iterator is being declared.
It’s important to note that not all STL containers support all five types of iterators. For example, the “vector” container supports random-access iterators, while the “list” container supports bidirectional iterators.

The table below summarizes the STL containers and the iterators supported by them in C++:

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-Programming-using-Cpp/assets/93253740/02099909-9175-4907-a97d-9b5b5dc6d0f5)


## Input Iterators in C++

The input iterator in C++ is the simplest among the five main iterators. It is primarily used for input operations, allowing the reading of values from the container. The input iterator is a one-way iterator, meaning it supports only forward iteration and cannot be decremented.

### Salient Features of Input Iterator:

- **Equality and Inequality Operator:**
  - Input iterators support equality and inequality comparison. Two input iterators are considered equal if they point to the same location, and unequal otherwise. This is denoted by the expressions it1 == it2 and it1 != it2.
- **Usability:**
  - Input iterators are one-way iterators, enabling iteration in a single direction. They work with single-pass algorithms, allowing sequential reading of values.
- **Dereferencing:**
  - Dereferencing an input iterator allows access to the data it points to, using the * operator. For example, *it is used to dereference the input iterator it.
- **Incrementable:**
  - Input iterators can be incremented in the forward direction using the post-increment (it++) or pre-increment (++it) operators.
- **Swappable:**
  - Values of two input iterators pointing to different positions can be easily swapped or exchanged with each other.

These features make the input iterator a fundamental component in C++ when working with STL containers and performing input operations.

### Limitations:

The limitations of input iterators in C++ include:

- **Read-only:**
  - Input iterators are restricted to reading data from the location to which they point. They cannot be used to assign values to the container.
- **Unidirectional:**
  - Input iterators can only move in a forward direction, meaning they can only be incremented and cannot be decremented.
- **Not suitable for multi-pass algorithms:**
  - Input iterators are not suitable for use in multi-pass algorithms where movement in both directions within a container is required.
- **Limited relational operators:**
  - Apart from equality and inequality operators, input iterators do not support other relational operators.
- **Limited arithmetic operators:**
  - Input iterators do not support arithmetic operators, unlike other iterator categories.

```cpp
#include<iostream>
#include<vector>

int main() {
  std::vector<int> v{ 1, 2, 3, 4, 5 };
  std::vector<int>::iterator it1, it2, temp;
  it1 = v.begin();
  it2 = v.end() - 1;
  std::cout << "Before Swapping" << std::endl;
  std::cout << "Dereferenced iterator 1: " << *it1 << " ";
  std::cout << "\n";
  std::cout << "Dereferenced iterator 2: " << *it2;
  std::cout << "\n\n";

  // swap the iterators
  temp = it1;
  it1 = it2;
  it2 = temp;

  // dereference and print iterators after swapping them
  std::cout << "Before Swapping" << std::endl;
  std::cout << "Dereferenced iterator 1: " << *it1 << " ";
  std::cout << "\n";
  std::cout << "Dereferenced iterator 2: " << *it2;
  std::cout << "\n\n";
  system("pause");
  return 0;
}
```

## Output Iterators in C++

Output iterators are used for output operations, allowing the assignment of values to the container but not providing access to the values. Similar to input iterators, output iterators are one-way iterators and can only be incremented in a forward direction.

### Salient Features of Output Iterator:

- **Equality and Inequality Operator:**
  - Output iterators support equality and inequality comparison, with two iterators being considered equal if they point to the same location.
- **Usability:**
  - Output iterators work with single-pass algorithms, allowing the assignment of a value only once.
- **Dereferencing:**
  - Dereferencing an output iterator provides the position for storing the value, using the * operator.
- **Incrementable:**
  - Output iterators are one-way iterators and can be incremented in the forward direction using the post-increment (it++) or pre-increment (++it) operators.
- **Swappable:**
  - Values of two output iterators pointing to different positions can be easily swapped or exchanged with each other.

### Limitations of Output Iterator:

- **Read-only:**
  - Output iterators do not provide access to the values and can only be used to assign values to the container.
- **Unidirectional:**
  - Similar to input iterators, output iterators can only be incremented and cannot be decremented.
- **Not suitable for multi-pass algorithms:**
  - Output iterators are not suitable for use in multi-pass algorithms where movement in both directions within a container is required.
- **Limited relational operators:**
  - Apart from equality and inequality operators, output iterators do not support other relational operators.
- **Limited arithmetic operators:**
  - Output iterators do not support arithmetic operators, similar to input iterators.

```cpp
#include <iostream>
#include <vector>
#include <iterator> 

int main() {
  std::vector<int> v1, v2;
  for (int i = 1; i <= 10; i++) {
    v1.push_back(i);
    v2.push_back(i + 2);
  }

  std::vector<int>::iterator itr = v1.begin();
  std::copy(v2.begin(), v2.end(), std::inserter(v1, itr));
  std::cout << "Elements of vector v1 after copying elements of v2 are :" << std::endl;
 
  for (itr = v1.begin(); itr != v1.end(); ++itr)
    std::cout << " " << *itr;

  std::cout << "\n\n";
  system("pause");
  return 0;
}
```
## Forward Iterators in C++

Forward iterators combine the functionalities of both input and output iterators, allowing both access to and assignment of values within the container. These iterators are unidirectional and can only traverse in the forward direction. Additionally, it’s important to note that bidirectional and random access iterators are considered valid forward iterators.

### Salient Features of Forward Iterator:

- **Equality and Inequality Operator:**
  - Similar to input and output iterators, forward iterators support equality and inequality comparison, determining whether two iterators point to the same location.
- **Usability:**
  - Forward iterators are widely used by every STL container class and provide the functionality for the simplest kind of loop through a container.
- **Dereferencing:**
  - As a combination of input and output iterators, forward iterators support both rvalue and lvalue dereferencing.
- **Incrementable:**
  - Forward iterators are unidirectional and can be incremented in the forward direction using the post-increment (it++) or pre-increment (++it) operators.
- **Swappable:**
  - Values of two forward iterators pointing to different positions can be easily swapped or exchanged with each other.

### Limitations of Forward Iterator:

- **Offset dereference operator not supported:**
  - Forward iterators do not support the offset dereference operator ([]), preventing the use of the offset operator to dereference a forward iterator.
- **Unidirectional:**
  - Similar to input and output iterators, forward iterators can only be incremented and cannot be decremented.
- **Limited relational operators:**
  - Apart from equality and inequality operators, forward iterators do not support other relational operators.
- **Limited arithmetic operators:**
  - Forward iterators do not support arithmetic operators, similar to input and output iterators.

Understanding the features and limitations of forward iterators is essential for effectively utilizing them in C++ programming.

```cpp
#include <iostream>
#include <vector>

template<class FIterator>
void forwardIterator(FIterator start, FIterator end) {
  while (start != end) {
    std::cout << *start << " ";
    start++;
  }
}

int main(){
  std::vector<int> v1;
  for (int i = 1; i <= 10; i++)
    v1.push_back(i + 2);

  forwardIterator(v1.begin(), v1.end());
  std::cout << "\n\n";
  system("pause");
  return 0;
}
```
### Bidirectional Iterators in C++

Bidirectional iterators provide the capability to iterate in both forward and backward directions, offering the same functionality as forward iterators with the addition of decrement operators. Containers like list, set, and multimap support bidirectional iterators, and random access iterators are also considered valid bidirectional iterators.

#### Salient Features of Bidirectional Iterator:

- **Equality and Inequality Operator:**
  - Bidirectional iterators support equality and inequality comparison, determining whether two iterators point to the same location.
- **Usability:**
  - Bidirectional iterators can be used for multi-pass algorithms, allowing read and write operations multiple times.
- **Dereferencing:**
  - Similar to forward iterators, bidirectional iterators support both rvalue and lvalue dereferencing.
- **Incrementable/Decrementable:**
  - Bidirectional iterators can move in both forward and backward directions, allowing both increment and decrement operations.
- **Swappable:**
  - Values of two bidirectional iterators pointing to different positions can be easily swapped or exchanged with each other.

#### Limitations of Bidirectional Iterator:

- **Offset dereference operator not supported:**
  - Bidirectional iterators, like forward iterators, do not support the offset dereference operator ([]), preventing the use of the offset operator to dereference a bidirectional iterator.
- **Limited relational operators:**
  - Apart from equality and inequality operators, bidirectional iterators do not support other relational operators.
- **Limited arithmetic operators:**
  - Bidirectional iterators do not support arithmetic operators, similar to forward iterators.

Understanding these features and limitations is essential for effectively utilizing bidirectional iterators in C++ programming, especially when working with containers that support bidirectional iteration.

```cpp
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1{ 10, 20, 30, 40, 50, 60 };
  std::vector<int>::iterator i1;
  std::vector<int>::reverse_iterator rItr;
  std::cout << "Values in original order: " << "\n";

  for (i1 = v1.begin(); i1 != v1.end(); i1++) 
    std::cout << *i1 << " ";

  std::cout << "\n\n";
  std::cout << "Values in reverse order: " << "\n";

  for (rItr = v1.rbegin(); rItr != v1.rend(); rItr++) 
    std::cout << *rItr << " ";

  std::cout << "\n\n";
  system("pause");
  return 0;
}
```

### Random-Access Iterators in C++

Random-access iterators are considered to be the most advanced iterators among the five types, offering bidirectional capabilities with additional support for random access.

#### Salient Features of Random-Access Iterator:

- **Equality and Inequality Operator:**
  - Random-access iterators support equality and inequality comparison, determining whether two iterators point to the same location.
- **Usability:**
  - Similar to bidirectional iterators, random-access iterators can be used in multi-pass algorithms, allowing for multiple read and write operations.
- **Dereferencing:**
  - Random-access iterators support both rvalue and lvalue dereferencing, similar to bidirectional iterators.
- **Incremental/Decremental:**
  - Random-access iterators can be incremented and decremented, providing multi-directional traversal capabilities.
- **Swappable:**
  - Values of two random-access iterators pointing to different positions can be easily swapped or exchanged with each other.
- **Relational Operators:**
  - Unlike other iterators, random-access iterators support all relational operators.
- **Arithmetic Operators:**
  - Random-access iterators support arithmetic operators, providing advanced manipulation capabilities.
- **Offset Dereference Operator:**
  - Random-access iterators support the offset dereference operator ([]), allowing for dereferencing using offsets.

Understanding the advanced capabilities and features of random-access iterators is crucial when working with complex data structures and algorithms in C++ programming. These iterators provide powerful traversal and manipulation capabilities, making them essential for efficient and flexible data handling.

```cpp
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec1 = { 10, 20, 30, 40, 50, 60 };

  std::vector<int>::iterator i1;
  std::vector<int>::iterator i2;
  i1 = vec1.begin();
  i2 = vec1.end();

  if (i1 < i2)
    std::cout << "Iterator i2 is greater than iterator i1.";

  int difference = i2 - i1;
  std::cout << "\nThe difference between i1 and i2 = " << difference;
  std::cout << "\n\n";
  system("pause");
  return 0;
}
```
### Operations of Iterators

#### begin() and end():
The `begin()` function returns an iterator pointing to the beginning position of the container, while the `end()` function returns an iterator pointing to the position after the last element of the container. These functions are fundamental for iterating over container elements.

```cpp
#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<int> vec {1, 2, 3, 4, 5};
    vector<int>::iterator itr;
    cout << "The vector elements are: ";
    for (itr = vec.begin(); itr < vec.end(); ++itr) 
        cout << *itr << " ";
    
    return 0;
}
```

#### advance():
The advance() function is used to increment the iterator position by the specified number of steps. It is particularly useful when we want to move the iterator to a specific position within the container.

```cpp
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    std::vector<int>::iterator itr = vec.begin();
    advance(itr, 3);
    std::cout << "The position of the iterator after advancing is: " << *itr << std::endl;
    system("pause");
    return 0;
}
```
#### next() and prev():
The next() and prev() functions return new iterators based on the given iterator and the number of steps to move forward or backward, respectively. These functions are useful for obtaining iterators to positions relative to the current iterator.

```cpp
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec{ 1, 2, 3, 4, 5 };
    std::vector<int>::iterator itr = vec.begin();
    std::vector<int>::iterator ftr = vec.end();
    auto newItr = next(itr, 3);
    auto newFtr = prev(ftr, 3);
    std::cout << "The position of the new iterator using next() is: " << *newItr << std::endl;
    std::cout << "The position of the new iterator using prev() is: " << *newFtr << std::endl;
    system("pause");
    return 0;
}
```

#### inserter():
The inserter() function is used to insert elements at any position within the container. It takes two arguments: the container and an iterator indicating the position where the elements should be inserted.

```cpp
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec { 1, 2, 3, 4, 5 }, newVec { 10, 20, 30 };
    std::vector<int>::iterator itr = vec.begin();
    advance(itr, 3);
    copy(newVec.begin(), newVec.end(), inserter(vec, itr));
    std::cout << "The new vector after inserting elements is: ";
    for (int& x : vec) 
        std::cout << x << " ";
    std::cout << std::endl;
    system("pause");
    return 0;
}
```
### Advantages of Iterators:

#### Simplified programming:
Iterators offer convenience and ease when writing code. They eliminate the need to worry about the size of the container, allowing easy iteration and access to the last element using the `end()` method. Additionally, they enable the modification of container elements without the need for manual shifting or labor-intensive operations.

### Disadvantages of Iterators:

#### Simultaneous handling of two data structures:
Iterators do not easily allow the simultaneous handling of two data structures, especially when the data of one structure determines the location in the other.

#### Inability to traverse backward:
While iterating through a container using iterators, it is not possible to traverse backward due to the inherent nature of iterators.

#### Inability to update container structure:
When traversing an STL container using an iterator, the structure of the container cannot be updated.

### Providers of Iterators:
The table below outlines the relationship between iterators and their respective provider containers:
![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-Programming-using-Cpp/assets/93253740/ae4beb92-6f8f-4bed-91b7-6c7a37e5fe34)





