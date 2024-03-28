Managing Capacity
The vector container in C++ offers several functions to query and adjust its capacity based on the number of elements it holds. By understanding these functions, programmers can optimize memory usage and ensure efficient storage management when working with the vector container.

Capacity Functions
empty: Checks whether the container is empty (public member function)
size: Returns the number of elements (public member function)
max_size: Returns the maximum possible number of elements (public member function)
reserve: Reserves storage (public member function)
capacity: Returns the number of elements that can be held in currently allocated storage (public member function)
shrink_to_fit: Reduces memory usage by freeing unused memory (public member function)
Example Use Cases
Using reserve() to allocate memory in advance can avoid the overhead of reallocations during the lifetime of the vector.
Using shrink_to_fit() can free up memory that is no longer needed by the vector.
