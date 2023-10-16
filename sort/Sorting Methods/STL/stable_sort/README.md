# stable_sort() in C++ STL

stable_sort() is used to sort the elements in the range [first, last) in ascending order. It is like std::sort, but stable_sort() keeps the relative order of elements with equivalent values. It comes under the <algorithm> header file.

Syntax:

template< class RandomIterator>
void stable_sort( RandomIterator first, RandomIterator last );
or

template< class RandomIterator, class Compare>
void stable_sort( RandomIterator first, RandomIterator last, Compare comp );

## Parameters:
1. first:  iterator pointing to the first element in the range.
2. last:  iterator pointing to the past last element in the range.
3. comp: predicate function that accepts two arguments and returns true if the two arguments are in order and false otherwise.

# How to Sort in Descending Order using stable_sort()?
Like sort(), stable_sort() takes a third parameter that is used to specify the order in which elements are to be sorted. We can pass “greater()” function to sort in decreasing order. This function does comparison in a way that puts greater element before. 

Syntax:
// arr is the array and n is the size
stable_sort(arr, arr + n, greater<int>());  
