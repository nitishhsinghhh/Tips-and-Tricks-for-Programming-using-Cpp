# Queue
The std::queue class is a container adaptor that gives the functionality of a queue - specifically, a FIFO (first-in, first-out) data structure.

The class template acts as a wrapper to the underlying container - only a specific set of functions is provided. The queue pushes the elements on the back of the underlying container and pops them from the front.
```cpp
Defined in header <queue>
template<
    class T,
    class Container = std::deque<T>
> class queue;
```

## Template parameters
T	-	The type of the stored elements. The behavior is undefined if T is not the same type as Container::value_type.
Container	-	The type of the underlying container to use to store the elements. The container must satisfy the requirements of SequenceContainer. Additionally, it must provide the following functions with the usual semantics:

- back(), e.g., std::deque::back(),
- front(), e.g. std::list::front(),
- push_back(), e.g., std::deque::push_back(),
- pop_front(), e.g., std::list::pop_front().
The standard containers std::deque and std::list satisfy these requirements. <br>

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
# Member Types
| Member type     | Definition                   |
|-----------------|------------------------------|
| container_type  | Container                    |
| value_type      | Container::value_type        |
| size_type       | Container::size_type         |
| reference       | Container::reference         |
| const_reference | Container::const_reference    |

# Member Objects
| Member name | Definition                     |
|-------------|--------------------------------|
| Container c | the underlying container (protected member object) |

# Member Functions
| Member Function | Definition                               |
|-----------------|------------------------------------------|
| (constructor)   | constructs the queue (public member function) |
| (destructor)    | destructs the queue (public member function)   |
| operator=       | assigns values to the container adaptor (public member function) |

| Element Access  |                                          |
|-------------|--------------------------------|
| front           | access the first element (public member function) |
| back            | access the last element (public member function) |

| Capacity        |                                          |
|-------------|--------------------------------|
| empty           | checks whether the container adaptor is empty (public member function) |
| size            | returns the number of elements (public member function) |

| Modifiers       |                                          |
|-------------|--------------------------------|
| push            | inserts element at the end (public member function) |
| push_range      | (C++23)inserts a range of elements at the end (public member function) |
| emplace         | (C++11) constructs element in-place at the end (public member function) |
| pop             | removes the first element (public member function) |
| swap            | (C++11) swaps the contents (public member function) |

| Non-member Functions |                                     |
|-------------|--------------------------------|
| operator==      |                                           |
| operator!=      |                                           |
| operator<       |                                           |
| operator<=      |  (C++20)lexicographically compares the values of two queues (function template) |
| operator>       |                                           |
| operator>=      |                                           |
| operator<=>     | 
| std::swap(std::queue) | (C++11) specializes the std::swap algorithm (function template) |

| Helper Classes  |                                          |
|-------------|--------------------------------|
| std::uses_allocator<std::queue> | (C++11) specializes the std::uses_allocator type trait (class template specialization) |
| std::formatter<std::queue> |  (C++23) formatting support for queue (class template specialization) |

```cpp
#include <cassert>
#include <iostream>
#include <queue>
 
int main() {
    std::queue<int> q;
 
    q.push(0); // back pushes 0
    q.push(1); // q = 0 1
    q.push(2); // q = 0 1 2
    q.push(3); // q = 0 1 2 3
 
    assert(q.front() == 0);
    assert(q.back() == 3);
    assert(q.size() == 4);
 
    q.pop(); // removes the front element, 0
    assert(q.size() == 3);
 
    // Print and remove all elements. Note that std::queue does not
    // support begin()/end(), so a range-for-loop cannot be used.
    std::cout << "q: ";
    for (; !q.empty(); q.pop())
        std::cout << q.front() << ' ';
    std::cout << '\n';
    assert(q.size() == 0);
}
// Output: q: 1 2 3
```
