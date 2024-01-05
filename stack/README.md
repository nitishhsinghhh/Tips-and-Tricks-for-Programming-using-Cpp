# What is Stack?

A stack is a linear data structure in which the insertion of a new element and removal of an existing element takes place at the same end represented as the top of the stack.

The `std::stack` class is a container adaptor that provides the functionality of a stack, which is a last-in, first-out (LIFO) data structure.

This class template acts as a wrapper to the underlying container, offering a specific set of functions. The stack pushes and pops elements from the back of the underlying container, referred to as the top of the stack.

## std::stack Class

### Template Parameters
T
The type of the stored elements. The behavior is undefined if T is not the same type as Container::value_type. <br>
Container 
The type of the underlying container to use to store the elements. The container must satisfy the requirements of SequenceContainer. Additionally, it must provide the following functions with the usual semantics: 
  - back(),
  - push_back(),
  - pop_back().
The standard containers std::vector (including std::vector<bool>), std::deque, and std::list satisfy these requirements. By default, if no container class is specified for a particular stack class instantiation, the standard container std::deque is used. 

### Member Types
| Member Type    | Definition              |
|----------------|-------------------------|
| container_type | Container               |
| value_type     | Container::value_type   |
| size_type      | Container::size_type    |
| reference      | Container::reference    |
| const_reference| Container::const_reference|

### Member Objects
| Member Name | Definition                                      |
|-------------|-------------------------------------------------|
| Container c | The underlying container (protected member object)|

### Member Functions
| Function    | Description                             |
|-------------|-----------------------------------------|
| constructor | Constructs the stack (public member function) |
| destructor  | Destructs the stack (public member function)  |
| operator=   | Assigns values to the container adaptor (public member function) |

### Element access
| Function    | Description                             |
|-------------|-----------------------------------------|
| top         | Accesses the top element (public member function) |


### Capacity
| Function    | Description                             |
|-------------|-----------------------------------------|
| empty       | Checks whether the container adaptor is empty (public member function) |
| size        | Returns the number of elements (public member function) |

### Modifiers
| Function    | Description                             |
|-------------|-----------------------------------------|
| push        | Inserts element at the top (public member function) |
| push_range (C++23) | Inserts a range of elements at the top (public member function) |
| emplace (C++11)    | Constructs element in-place at the top (public member function) |
| pop         | Removes the top element (public member function) |
| swap (C++11)     | Swaps the contents (public member function) |

### Non-member Functions
| Function       | Description                                           |
|----------------|-------------------------------------------------------|
| operator==     | Lexicographically compares the values of two stacks (function template) |
| operator!=     | Lexicographically compares the values of two stacks (function template) |
| operator<      | Lexicographically compares the values of two stacks (function template) |
| operator<=     | Lexicographically compares the values of two stacks (function template) |
| operator>      | Lexicographically compares the values of two stacks (function template) |
| operator>=     | Lexicographically compares the values of two stacks (function template) |
| operator<=> (C++20)  | Lexicographically compares the values of two stacks (function template) |
| std::swap(std::stack) | Specializes the std::swap algorithm (function template) |

### Helper Classes
| Class                                     | Description                   |
|-------------------------------------------|-------------------------------------------------------|
| std::uses_allocator<std::stack>           | Specializes the std::uses_allocator type trait (class template specialization) |

### Complexity Analysis
The time complexity for the operations of the std::stack class depends on the underlying container used. For the standard containers such as std::vector, std::deque, and std::list, the time complexity for the operations is as follows:

- Accessing the top element (top): O(1)
- Checking if the stack is empty (empty): O(1)
- Retrieving the number of elements (size): O(1)
- Inserting an element at the top (push): O(1)
- Removing the top element (pop): O(1)
- Swapping the contents (swap): O(1)

The time complexity for the push_range and emplace functions would depend on the complexity of the underlying operations used to perform these functions.
