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
| top         | Accesses the top element (public member function) |
| empty       | Checks whether the container adaptor is empty (public member function) |
| size        | Returns the number of elements (public member function) |
| push        | Inserts element at the top (public member function) |
| push_range  | Inserts a range of elements at the top (public member function) |
| emplace     | Constructs element in-place at the top (public member function) |
| pop         | Removes the top element (public member function) |
| swap        | Swaps the contents (public member function) |

### Non-member Functions
| Function       | Description                                           |
|----------------|-------------------------------------------------------|
| operator==     | Lexicographically compares the values of two stacks (function template) |
| operator!=     | Lexicographically compares the values of two stacks (function template) |
| operator<      | Lexicographically compares the values of two stacks (function template) |
| operator<=     | Lexicographically compares the values of two stacks (function template) |
| operator>      | Lexicographically compares the values of two stacks (function template) |
| operator>=     | Lexicographically compares the values of two stacks (function template) |
| operator<=>    | Lexicographically compares the values of two stacks (function template) |
| std::swap(std::stack) | Specializes the std::swap algorithm (function template) |

### Helper Classes
| Class                                     | Description                                           |
|-------------------------------------------|-------------------------------------------------------|
| std::uses_allocator<std::stack>           | Specializes the std::uses_allocator type trait (class template specialization) |

