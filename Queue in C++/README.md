# Queue
A Queue is a standard Abstract Data Type. It has several properties associated with it:

1. It is a linear data structure - all components are arranged in a straight line.
2. It has a grow/decay rule - queues add and remove from opposite ends.
3. Knowledge of how they're constructed shouldn't be integral in using them because they have public interfaces available.

Queues can be modeled using Sequential Arrays or Linked-Lists.
If you're using an array there are some things to consider because you grow in one direction so you will eventually run out of array. You then have some choices to make (shift versus grow). If you choose to shift back to the beginning of the array (wrap around) you have to make sure the head and tail don't overlap. If you choose to simply grow the queue, you have a lot of wasted memory.

If you're using a Linked-List, you can insert anywhere and the queue will grow from the tail and shrink from the head. You also don't have to worry about filling up your list and having to wrap/shift elements or grow.

However you decide to implement the queue, remember that Queues should provide some common interface to use the queue. Here are some examples:

1. enqueue - Inserts an element at the back (tail) of the queue
2. dequeue - Remove an element from the front (head) of a non-empty queue.
3. empty - Returns whether the queue is empty or not
4. size - Returns the size of the queue

There are other operations you might want to add to your queue (In C++, you may want an iterator to the front/back of your queue) but how you build your queue should not make a difference with regards to the operations it provides.

However, depending on how you want to use your queue, there are better ways to build it. The usual tradeoff is insert/removal time versus search time. Here is [a decent reference.](https://en.wikipedia.org/wiki/Linked_list#Linked_lists_vs._arrays) If you would like to read more, please follow the [link provided.](https://en.cppreference.com/w/cpp/container/queue)

## Member types

| Member type          | Definition                                        |
|----------------------|---------------------------------------------------|
| value_type           | T                                                 |
| allocator_type       | Allocator                                          |
| size_type            | Unsigned integer type (usually std::size_t)       |
| difference_type      | Signed integer type (usually std::ptrdiff_t)      |
| reference            | value_type&                                        |
| const_reference      | const value_type&                                  |
| pointer              |                                                   |
| Allocator::pointer   | (until C++11)                                     |
| std::allocator_traits<Allocator>::pointer | (since C++11) |
| const_pointer        |                                                   |
| Allocator::const_pointer | (until C++11)                                 |
| std::allocator_traits<Allocator>::const_pointer | (since C++11) |
| iterator             | LegacyRandomAccessIterator to value_type          |
| const_iterator       | LegacyRandomAccessIterator to const value_type    |
| reverse_iterator     | std::reverse_iterator<iterator>                   |
| const_reverse_iterator | std::reverse_iterator<const_iterator>            |

## Member functions

|  Member type     |         Definition                                    |
|----------------------|---------------------------------------------------|
| (constructor)        | constructs the deque                               |
| (destructor)         | destructs the deque                                |
| operator=            | assigns values to the container                   |
| assign               | assigns values to the container                   |
| assign_range         | (C++23)                                           |
| get_allocator        | returns the associated allocator                  |

## Element access
|  Member type     |         Definition                                    |
|----------------------|---------------------------------------------------|
| at                   | access specified element with bounds checking     |
| operator[]           | access specified element                           |
| front                | access the first element                           |
| back                 | access the last element                            |

## Iterators
|  Member type     |         Definition                                    |
|----------------------|---------------------------------------------------|
| begin                | cbegin (C++11)                                    |
| end                  | cend (C++11)                                      |
| rbegin               | crbegin (C++11)                                   |
| rend                 | crend (C++11)                                     |

## Capacity
|  Member type     |         Definition                                    |
|----------------------|---------------------------------------------------|
| empty                | checks whether the container is empty             |
| size                 | returns the number of elements                    |
| max_size             | returns the maximum possible number of elements   |
| shrink_to_fit        | (DR*)                                             |

## Modifiers
|  Member type     |         Definition                                    |
|----------------------|---------------------------------------------------|
| clear                | clears the contents                               |
| insert               | inserts elements                                  |
| insert_range         | (C++23)                                           |
| emplace              | (C++11)                                           |
| erase                | erases elements                                   |
| push_back            | adds an element to the end                        |
| emplace_back         | (C++11)                                           |
| append_range         | (C++23)                                           |
| pop_back             | removes the last element                           |
| push_front           | inserts an element to the beginning               |
| emplace_front        | (C++11)                                           |
| prepend_range        | (C++23)                                           |
| pop_front            | removes the first element                         |
| resize               | changes the number of elements stored             |
| swap                 | swaps the contents                                |

## Non-member functions 
|  Member type     |         Definition                                    |
|----------------------|---------------------------------------------------|
| operator==           |                                                   |
| operator!=           |                                                   |
| operator<            |                                                   |
| operator<=           |                                                   |
| operator>            |                                                   |
| operator>=           |                                                   |
| operator<=>          | (removed in C++20)                                |
| std::swap(std::deque) | specializes the std::swap algorithm               |
| erase(std::deque)    | erase_if(std::deque) (C++20)                      |
