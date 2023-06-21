#include <iostream>
#include <iterator>
#include <list>

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
void advance(Iterator& it, Distance n) {
    typename std::iterator_traits<Iterator>::iterator_category category;
    advanceImpl(it, n, category);
}

int main() {
    std::list<int> myList = {1, 2, 3, 4, 5};

    auto it = myList.begin();
    std::advance(it, 2);

    std::cout << "Element after advancing: " << *it << std::endl;

    return 0;
}
