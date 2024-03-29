# std::list

```CPP[]
Defined in header <list>
template<
    class T,
    class Allocator = std::allocator<T>
> class list;
(1)	
namespace pmr {
    template< class T >
    using list = std::list<T, std::pmr::polymorphic_allocator<T>>;
}
```
std::list is a container that supports constant time insertion and removal of elements from anywhere in the container. Fast random access is not supported. It is usually implemented as a doubly-linked list. Compared to std::forward_list this container provides bidirectional iteration capability while being less space efficient.

Adding, removing and moving the elements within the list or across several lists does not invalidate the iterators or references. An iterator is invalidated only when the corresponding element is deleted.

std::list meets the requirements of Container, AllocatorAwareContainer, SequenceContainer and ReversibleContainer.

## Template parameters
- The type of the elements.
- T must meet the requirements of CopyConstructible. T must meet the requirements of CopyAssignable if list::operator= or list::assign is instantiated with T. (until C++11)
- The requirements that are imposed on the elements depend on the actual operations performed on the container. Generally, it is required that the element type is a complete type and meets the requirements of Erasable, but many member functions impose stricter requirements. (since C++11)
- (until C++17) The requirements that are imposed on the elements depend on the actual operations performed on the container. Generally, it is required that the element type meets the requirements of Erasable, but many member functions impose stricter requirements. This container (but not its members) can be instantiated with an incomplete element type if the allocator satisfies the allocator completeness requirements.

## Member types
| Member Type         | Definition                                     |
|---------------------|------------------------------------------------|
| value_type          | T                                              |
| allocator_type      | Allocator                                      |
| size_type           | Unsigned integer type (usually std::size_t)   |
| difference_type     | Signed integer type (usually std::ptrdiff_t)   |
| reference           | value_type&                                    |
| const_reference     | const value_type&                              |
| pointer             |                                                |
| Allocator::pointer  | (until C++11)                                  |
| allocator_traits<Allocator>::pointer | (since C++11) |
| const_pointer       |                                                |
| Allocator::const_pointer | (until C++11)                              |
| allocator_traits<Allocator>::const_pointer | (since C++11) |
| iterator            | LegacyBidirectionalIterator to value_type      |
| const_iterator      | LegacyBidirectionalIterator to const value_type|
| reverse_iterator    | std::reverse_iterator<iterator>                |
| const_reverse_iterator | std::reverse_iterator<const_iterator>        |

## Member functions
| Member Function     | Description                                    |
|---------------------|------------------------------------------------|
| (constructor)       | constructs the list                            |
| (destructor)        | destructs the list                             |
| operator=           | assigns values to the container               |
| assign              | assigns values to the container               |
| assign_range        | (C++23) assigns a range of values to the container |
| get_allocator       | returns the associated allocator               |

## Element access
| Element access     | Description                                    |
|---------------------|------------------------------------------------|
| front               | access the first element                       |
| back                | access the last element                        |

## Iterators
| Iterators    | Description                                    |
|---------------------|------------------------------------------------|
| begin               | cbegin (C++11) returns an iterator to the beginning |
| end                 | cend (C++11) returns an iterator to the end   |
| rbegin              | crbegin (C++11) returns a reverse iterator to the beginning |
| rend                | crend (C++11) returns a reverse iterator to the end |

## Capacity
| Capacity            | Description                                    |
|---------------------|------------------------------------------------|
| empty               | checks whether the container is empty         |
| size                | returns the number of elements                 |

## Modifiers
| Modifiers           | Description                                    |
|---------------------|------------------------------------------------|
| max_size            | returns the maximum possible number of elements |
| clear               | clears the contents                            |
| insert              | inserts elements                               |
| insert_range        | (C++23) inserts a range of elements           |
| emplace             | (C++11) constructs element in-place           |
| erase               | erases elements                                |
| push_back           | adds an element to the end                     |
| emplace_back        | (C++11) constructs an element in-place at the end |
| append_range        | (C++23) adds a range of elements to the end   |
| pop_back            | removes the last element                       |
| push_front          | inserts an element to the beginning           |
| emplace_front       | (C++11) constructs an element in-place at the beginning |
| prepend_range       | (C++23) adds a range of elements to the beginning |
| pop_front           | removes the first element                      |
| resize              | changes the number of elements stored         |
| swap                | swaps the contents                             |

## Operations
| Operations          | Description                                    |
|---------------------|------------------------------------------------|
| merge               | merges two sorted lists                        |
| splice              | moves elements from another list               |
| remove              | remove_if removes elements satisfying specific criteria |
| reverse             | reverses the order of the elements            |
| unique              | removes consecutive duplicate elements         |
| sort                | sorts the elements                             |

## Non-member Function
| Non-member Function | Description                                    |
|---------------------|------------------------------------------------|
| operator==          | equality comparison                            |
| operator!=          | inequality comparison                          |
| operator<           | less than comparison                           |
| operator<=          | less than or equal to comparison               |
| operator>           | greater than comparison                        |
| operator>=          | greater than or equal to comparison            |
| operator<=>         | (removed in C++20) lexicographically compares the values of two lists |
| std::swap(std::list) | specializes the std::swap algorithm            |
| erase(std::list)    | (C++20) erases all elements satisfying specific criteria |
| erase_if(std::list) | (C++20) erases all elements satisfying specific criteria |

### Example 

```cpp[]
#include <algorithm>
#include <iostream>
#include <list>
 
int main()
{
    // Create a list containing integers
    std::list<int> l = {7, 5, 16, 8};
 
    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);
 
    // Insert an integer before 16 by searching
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end())
        l.insert(it, 42);
 
    // Print out the list
    std::cout << "l = { ";
    for (int n : l)
        std::cout << n << ", ";
    std::cout << "};\n";
}
// Output: l = { 25, 7, 5, 42, 16, 8, 13, };
```
