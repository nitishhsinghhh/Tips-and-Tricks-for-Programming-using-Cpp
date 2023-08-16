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

However, depending on how you want to use your queue, there are better ways to build it. The usual tradeoff is insert/removal time versus search time. Here is [a decent reference.](https://en.wikipedia.org/wiki/Linked_list#Linked_lists_vs._arrays)
