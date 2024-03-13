# C++ Standard Template Library
The C++ STL (Standard Template Library) is a generic collection of class templates and
algorithms that allow programmers to easily implement standard data structures like
queues, lists, and stacks.

## Containers library
The Containers library is a generic collection of class templates and algorithms that allow programmers to easily implement common data structures like queues, lists and stacks. There are two(until C++11) three (since C++11) classes of containers:
- sequence containers,
- associative containers, and
- unordered associative containers, (since C++11)

each of which is designed to support a different set of operations.

The container manages the storage space that is allocated for its elements and provides member functions to access them, either directly or through iterators (objects with properties similar to pointers).

Most containers have at least several member functions in common, and share functionalities. Which container is the best for the particular application depends not only on the offered functionality, but also on its efficiency for different workloads.

### Sequence containers
Sequence containers implement data structures which can be accessed sequentially.

| Sequence Container      | Description              |  
|-------------------------|--------------------------|  
| array (C++11)           | Static contiguous array  |  
| vector                 | Dynamic contiguous array |  
| deque                  | Double-ended queue       |  
| forward_list (C++11)   | Singly-linked list       |  
| list                   | Doubly-linked list       |  

### Associative containers
Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).
| Associative Container   | Description                                         |  
|-------------------------|-----------------------------------------------------|  
| set                     | Collection of unique keys, sorted by keys          |  
| map                     | Collection of key-value pairs, sorted by keys       |  
| multiset                | Collection of keys, sorted by keys                  |  
| multimap                | Collection of key-value pairs, sorted by keys       |  

### Unordered associative containers (since C++11)
Unordered associative containers implement unsorted (hahe/shed) data structures that can be quickly searched (O(1) average, O(n) worst-case complexity).
| Unordered Associative Container | Description                                       |  
|---------------------------------|---------------------------------------------------|  
| unordered_set (C++11)           | Collection of unique keys, hahe/shed by keys         |  
| unordered_map (C++11)           | Collection of key-value pairs, hahe/shed by keys     |  
| unordered_multiset (C++11)      | Collection of keys, hahe/shed by keys                |  
| unordered_multimap (C++11)      | Collection of key-value pairs, hahe/shed by keys     |  

### Container adaptors
Container adaptors provide a different interface for sequential containers.
| Container Adaptor  | Description                                                 |  
|--------------------|-------------------------------------------------------------|  
| stack              | Adapts a container to provide a stack (LIFO data structure) |  
| queue              | Adapts a container to provide a queue (FIFO data structure) |  
| priority_queue     | Adapts a container to provide a priority queue             |  
| flat_set (C++23)   | Adapts a container to provide a collection of unique keys, sorted by keys |  
| flat_map (C++23)   | Adapts two containers to provide a collection of key-value pairs, sorted by unique keys |  
| flat_multiset (C++23) | Adapts a container to provide a collection of keys, sorted by keys |  
| flat_multimap (C++23) | Adapts two containers to provide a collection of key-value pairs, sorted by keys |  

### Views
Views provide flexible facilities for interacting with one- or multi-dimensional views over a non-owning array of elements.
| View    | Description                                                        |  
|---------|--------------------------------------------------------------------|  
| span    | A non-owning view over a contiguous sequence of objects (C++20)     |  
| mdspan  | A multi-dimensional non-owning array view (C++23)                   |  


The idea behind the C++ STL is that the hard part of using complex data structures has
already been completed. If a programmer would like to use a stack of integers, all that he/she
has to do is use this code:<br>
```cpp
stack<int> myStack;
```
With minimal effort, he/she can now push() and pop() integers onto this stack. Through the
magic of C++ Templates, he/she could specify any data type, not just integers. The STL
Stack class will provide generic functionality of a stack, regardless of the data in the
stack.<br>
In addition, the STL also provides a bunch of useful algorithms -- like searching, sorting,
and general-purpose iterating algorithms -- that can be used on a variety of data
structures. <br>

## C++ Iterators
Iterators are used to access members of the container classes, and can be used in a similar
manner to pointers. For example, one might use an iterator to step through the elements
of a vector. There are several different types of iterators:

| Iterator Type          | Description                                                                                                      |  
|------------------------|------------------------------------------------------------------------------------------------------------------|  
| input_iterator         | Reads values with forward movement. These can be incremented, compared, and dereferenced.                        |  
| output_iterator        | Writes values with forward movement. These can be incremented and dereferenced.                                 |  
| forward_iterator       | Reads or writes values with forward movement. These combine the functionality of input and output iterators with the ability to store the iterator's value. |  
| bidirectional_iterator | Reads and writes values with forward and backward movement. Similar to forward iterators, but can be incremented and decremented.              |  
| random_iterator        | Reads and writes values with random access. These are powerful iterators, combining the functionality of bidirectional iterators with the ability to perform pointer arithmetic and comparisons. |  
| reverse_iterator       | Either a random iterator or a bidirectional iterator that moves in reverse direction.                               |  

Each of the container classes is associated with a type of iterator, and each of the STL
algorithms uses a certain type of iterator. For example, vectors are associated with
random-access iterators, which means that they can use algorithms that require random
access. Since random-access iterators encompass all of the characteristics of the other
iterators, vectors can use algorithms designed for other iterators as well.<br>
The following code creates and uses an iterator with a vector:
```cpp
#include <iostream>
#include <vector>
int main() {
	std::vector<int> the_vector;
	std::vector<int>::iterator the_iterator;
	for (int i = 0; i < 10; i++)
		the_vector.push_back(i);
	int total = 0;
	the_iterator = the_vector.begin();
	while (the_iterator != the_vector.end()) {
		total += *the_iterator;
		the_iterator++;
	}
	std::cout << "Total=" << total << std::endl;
}
```
Notice that you can access the elements of the container by dereferencing the iterator. 
