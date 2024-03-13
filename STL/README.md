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

## Algorithms library

The algorithms library defines functions for a variety of purposes (e.g. searching, sorting, counting, manipulating) that operate on ranges of elements. Note that a range is defined as [first, last) where last refers to the element past the last element to inspect or modify.

| Algorithm                  | Description                                                                                         |
|---------------------------|-----------------------------------------------------------------------------------------------------|
| accumulate                | Sum up a range of elements                                                                          |
| adjacent_difference       | Compute the differences between adjacent elements in a range                                       |
| adjacent_find             | Find two items that are adjacent to each other                                                      |
| binary_search             | Determine if an element exists in a certain range                                                   |
| copy                      | Copy some range of elements to a new location                                                        |
| copy_backward             | Copy a range of elements in backwards order                                                         |
| copy_n                    | Copy N elements                                                                                     |
| count                     | Return the number of elements matching a given value                                                 |
| count_if                  | Return the number of elements for which a predicate is true                                         |
| equal                     | Determine if two sets of elements are the same                                                      |
| equal_range               | Search for a range of elements that are all equal to a certain element                               |
| fill                      | Assign a range of elements a certain value                                                          |
| fill_n                    | Assign a value to some number of elements                                                           |
| find                      | Find a value in a given range                                                                       |
| find_end                  | Find the last sequence of elements in a certain range                                               |
| find_first_of             | Search for any one of a set of elements                                                             |
| find_if                   | Find the first element for which a certain predicate is true                                        |
| for_each                  | Apply a function to a range of elements                                                             |
| generate                  | Save the result of a function in a range                                                            |
| generate_n                | Save the result of N applications of a function                                                     |
| includes                  | Returns true if one set is a subset of another                                                      |
| inner_product             | Compute the inner product of two ranges of elements                                                 |
| inplace_merge             | Merge two ordered ranges in-place                                                                   |
| is_heap                   | Returns true if a given range is a heap                                                             |
| is_sorted                 | Returns true if a range is sorted in ascending order                                                |
| iter_swap                 | Swaps the elements pointed to by two iterators                                                      |
| lexicographical_compare   | Returns true if one range is lexicographically less than another                                    |
| lexicographical_compare_3way | Determines if one range is lexicographically less than or greater than another                   |
| lower_bound               | Search for the first place that a value can be inserted while preserving order                      |
| make_heap                 | Create a heap out of a range of elements                                                            |
| max                       | Returns the larger of two elements                                                                 |
| max_element               | Returns the largest element in a range                                                              |
| merge                     | Merge two sorted ranges                                                                             |
| min                       | Returns the smaller of two elements                                                                 |
| min_element               | Returns the smallest element in a range                                                             |
| mismatch                  | Finds the first position where two ranges differ                                                    |
| next_permutation          | Generates the next greater lexicographic permutation of a range of elements                         |
| nth_element               | Put one element in its sorted location and make sure that no elements to its left are greater than any elements to its right |
| partial_sort              | Sort the first N elements of a range                                                                |
| partial_sort_copy         | Copy and partially sort a range of elements                                                         |
| partial_sum               | Compute the partial sum of a range of elements                                                      |
| partition                 | Divide a range of elements into two groups                                                          |
| pop_heap                  | Remove the largest element from a heap                                                              |
| prev_permutation          | Generates the next smaller lexicographic permutation of a range of elements                         |
| push_heap                 | Add an element to a heap                                                                            |
| random_sample             | Randomly copy elements from one range to another                                                    |
| random_sample_n           | Sample N random elements from a range                                                               |
| random_shuffle            | Randomly re-order elements in 
| remove                  | Remove elements equal to a certain value                                                                      |  
| remove_copy             | Copy a range of elements omitting those that match a certain value                                            |  
| remove_copy_if          | Create a copy of a range of elements, omitting any for which a predicate is true                               |  
| remove_if               | Remove all elements for which a predicate is true                                                             |  
| replace                 | Replace every occurrence of a value in a range with another value                                              |  
| replace_copy            | Copy a range, replacing certain elements with new ones                                                        |  
| replace_copy_if         | Copy a range of elements, replacing those for which a predicate is true                                        |  
| replace_if              | Change the values of elements for which a predicate is true                                                    |  
| reverse                 | Reverse elements in some range                                                                                |  
| reverse_copy            | Create a copy of a range that is reversed                                                                     |  
| rotate                  | Move the elements in some range to the left by some amount                                                    |  
| rotate_copy             | Copy and rotate a range of elements                                                                           |  
| search                  | Search for a range of elements                                                                                |  
| search_n                | Search for N consecutive copies of an element in some range                                                   |  
| set_difference          | Computes the difference between two sets                                                                     |  
| set_intersection        | Computes the intersection of two sets                                                                        |  
| set_symmetric_difference| Computes the symmetric difference between two sets                                                           |  
| set_union               | Computes the union of two sets                                                                               |  
| sort                    | Sort a range into ascending order                                                                             |  
| sort_heap               | Turns a heap into a sorted range of elements                                                                  |  
| stable_partition        | Divide elements into two groups while preserving their relative order                                         |  
| stable_sort             | Sort a range of elements while preserving order between equal elements                                        |  
| swap                    | Swap the values of two objects                                                                               |  
| swap_ranges             | Swaps two ranges of elements                                                                                 |  
| transform               | Applies a function to a range of elements                                                                     |  
| unique                  | Remove consecutive duplicate elements in a range                                                              |  
| unique_copy             | Create a copy of some range of elements that contains no consecutive duplicates                               |  
| upper_bound             | Searches for the last possible location to insert an element into an ordered range                           |  

