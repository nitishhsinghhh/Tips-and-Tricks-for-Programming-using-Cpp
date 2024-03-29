# std::forward_list

```cpp
// Defined in header <forward_list>

// (1)	(since C++11)
template<
    class T,
    class Allocator = std::allocator<T>
> class forward_list;

// (2)	(since C++17)
namespace pmr {
    template< class T >
    using forward_list = std::forward_list<T, std::pmr::polymorphic_allocator<T>>;
}
```

std::forward_list is a container that supports fast insertion and removal of elements from anywhere in the container. Fast random access is not supported. It is implemented as a singly-linked list. Compared to std::list this container provides more space efficient storage when bidirectional iteration is not needed.

Adding, removing and moving the elements within the list, or across several lists, does not invalidate the iterators currently referring to other elements in the list. However, an iterator or reference referring to an element is invalidated when the corresponding element is removed (via erase_after) from the list.

std::forward_list meets the requirements of Container (except for the size member function and that operator=='s complexity is always linear), AllocatorAwareContainer and SequenceContainer.

## Template parameters

T	-	The type of the elements.<br>
The requirements that are imposed on the elements depend on the actual operations performed on the container. Generally, it is required that element type is a complete type and meets the requirements of Erasable, but many member functions impose stricter requirements.	(until C++17)
The requirements that are imposed on the elements depend on the actual operations performed on the container. Generally, it is required that element type meets the requirements of Erasable, but many member functions impose stricter requirements. This container (but not its members) can be instantiated with an incomplete element type if the allocator satisfies the allocator completeness requirements.

## Member types
| Member type      | Definition                                           |
|------------------|------------------------------------------------------|
| value_type       | T                                                    |
| allocator_type   | Allocator                                            |
| size_type        | Unsigned integer type (usually std::size_t)          |
| difference_type  | Signed integer type (usually std::ptrdiff_t)         |
| reference        | value_type&                                          |
| const_reference  | const value_type&                                    |
| pointer          | std::allocator_traits<Allocator>::pointer            |
| const_pointer    | std::allocator_traits<Allocator>::const_pointer      |
| iterator         | LegacyForwardIterator to value_type                  |
| const_iterator   | LegacyForwardIterator to const value_type            |

## Member functions
| Member function | Description                               |
|-----------------|-------------------------------------------|
| constructor     | Constructs the forward_list               |
| destructor      | Destructs the forward_list                |
| operator=       | Assigns values to the container           |
| assign          | Assigns values to the container           |
| assign_range    | Assigns a range of values to the container (C++23) |
| get_allocator   | Returns the associated allocator           |

## Element access
| Element access | Description                    |
|----------------|--------------------------------|
| front          | Accesses the first element      |

## Iterators
| Iterator      | Description                                 |
|---------------|---------------------------------------------|
| before_begin   | Returns an iterator to the element before the beginning (public member function) |
| cbefore_begin  | Returns a constant iterator to the element before the beginning (public member function) |
| begin          | Returns an iterator to the beginning (public member function) |
| cbegin         | Returns a constant iterator to the beginning (public member function) |
| end            | Returns an iterator to the end (public member function) |
| cend           | Returns a constant iterator to the end (public member function) |

## Capacity
| Capacity | Description                                        |
|----------|----------------------------------------------------|
| empty    | Checks whether the container is empty (public member function) |
| max_size | Returns the maximum possible number of elements (public member function) |

## Modifier
| Modifier          | Description                                       |
|-------------------|---------------------------------------------------|
| clear             | Clears the contents                               |
| insert_after      | Inserts elements after an element                 |
| emplace_after     | Constructs elements in-place after an element     |
| insert_range_after | Inserts a range of elements after an element (C++23) |
| erase_after       | Erases an element after an element                |
| push_front        | Inserts an element to the beginning              |
| emplace_front     | Constructs an element in-place at the beginning   |
| prepend_range     | Adds a range of elements to the beginning (C++23) |
| pop_front         | Removes the first element                         |
| resize            | Changes the number of elements stored            |
| swap              | Swaps the contents                                |

## Operation
| Operation    | Description                                           |
|--------------|-------------------------------------------------------|
| merge        | Merges two sorted lists                                |
| splice_after | Moves elements from another forward_list               |
| remove       | Removes elements satisfying specific criteria          |
| remove_if    | Removes elements satisfying specific criteria          |
| reverse      | Reverses the order of the elements                     |
| unique       | Removes consecutive duplicate elements                 |
| sort         | Sorts the elements                                     |

## Non-member functions
| Non-Member Function  | Description                                                     |
|----------------------|-----------------------------------------------------------------|
| operator==           | Compares the values of two forward_lists for equality            |
| operator!=           | Compares the values of two forward_lists for inequality          |
| operator<            | Compares the values of two forward_lists (less than)             |
| operator<=           | Compares the values of two forward_lists (less than or equal to) |
| operator>            | Compares the values of two forward_lists (greater than)          |
| operator>=           | Compares the values of two forward_lists (greater than or equal to) |
| operator<=>          | Lexicographically compares the values of two forward_lists (C++20) |
| std::swap(std::forward_list) | Specializes the std::swap algorithm for forward_list (C++11)   |
| erase(std::forward_list)    | Erases all elements from the forward_list (C++20)               |
| erase_if(std::forward_list) | Erases all elements satisfying specific criteria (C++20)        |
