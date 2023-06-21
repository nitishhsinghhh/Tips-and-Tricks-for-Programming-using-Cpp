#include <iostream>
#include <iterator>
#include <list>
using namespace std;

// Advance implementation
template<class Iterator, class Distance>
void advanceImpl(Iterator& it, Distance n, std::random_access_iterator_tag) {
    it += n;
}

template<class Iterator, class Distance>
void advanceImpl(Iterator& it, Distance n, std::bidirectional_iterator_tag) {
    if (n >= 0) {
        while (n--)
            ++it;
    } else {
        while (n++)
            --it;
    }
}

template<class Iterator, class Distance>
void advanceImpl(Iterator& it, Distance n, std::input_iterator_tag) {
    if (n < 0) {
        throw std::runtime_error("advance: negative distance on input iterator");
    }
    while (n--)
        ++it;
}

template<class Iterator, class Distance>
void advance1(Iterator& it, Distance n) {
    typename std::iterator_traits<Iterator>::iterator_category category;
    advanceImpl(it, n, category);
}

int main() {

    // Create a double-linked list
    list<int> dblList = {1, 2, 3, 4, 5};

    // Find the middle iterator
    auto middleIterator = dblList.begin();
    advance(middleIterator, dblList.size() / 2);

    // Delete the middle element
    dblList.erase(middleIterator);

    // Print the updated list
    for (const auto& element : dblList) 
        cout << element << " ";
        
    cout<< endl;

    // Test Advance1 func

    // Create a double-linked list
    list<int> dblList1 = {1, 2, 3, 4, 5};

    // Find the middle iterator
    auto middleIterator1 = dblList1.begin();
    advance1(middleIterator1, dblList1.size() / 2);

    // Delete the middle element
    dblList1.erase(middleIterator1);

    // Print the updated list
    for (const auto& element : dblList1) 
        cout << element << " ";
    
    cout << endl;    
    
    return 0;
}
