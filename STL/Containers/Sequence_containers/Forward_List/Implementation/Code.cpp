#include <iostream>
#include <memory>
#include <iterator>
#include <cstddef>

template<class T, class Allocator = std::allocator<T>>
class forward_list;

namespace detail {

    template<class T>
    struct forward_list_node {
        T value;
        forward_list_node<T>* next;

        forward_list_node(const T& val) : value(val), next(nullptr) {}
    };

    template<class T, class Allocator>
    struct forward_list_alloc_base {
        using node_type = forward_list_node<T>;
        using node_allocator_type =
            typename std::allocator_traits<Allocator>::template rebind_alloc<node_type>;
        using node_allocator_traits = std::allocator_traits<node_allocator_type>;

        node_allocator_type allocator;

        forward_list_alloc_base(const Allocator& alloc) : allocator(alloc) {}

        node_type* allocate_node(const T& val) {
            node_type* node = node_allocator_traits::allocate(allocator, 1);
            node_allocator_traits::construct(allocator, node, val);
            return node;
        }

        void deallocate_node(node_type* node) {
            node_allocator_traits::destroy(allocator, node);
            node_allocator_traits::deallocate(allocator, node, 1);
        }
    };

    template<class T, class Pointer, class Reference>
    struct forward_list_iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = Pointer;
        using reference = Reference;

        forward_list_node<T>* node;

        explicit forward_list_iterator(forward_list_node<T>* n) : node(n) {}

        forward_list_iterator& operator++() {
            node = node->next;
            return *this;
        }

        forward_list_iterator operator++(int) {
            forward_list_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        bool operator==(const forward_list_iterator& other) const {
            return node == other.node;
        }

        bool operator!=(const forward_list_iterator& other) const {
            return !(*this == other);
        }

        reference operator*() const {
            return node->value;
        }

        pointer operator->() const {
            return &(node->value);
        }
    };

} // namespace detail

template<class T, class Allocator>
class forward_list : private detail::forward_list_alloc_base<T, Allocator> {
public:
    using value_type = T;
    using allocator_type = Allocator;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = detail::forward_list_iterator<T, pointer, reference>;
    using const_iterator = detail::forward_list_iterator<T, const_pointer, const_reference>;
    using size_type = std::size_t;

private:
    detail::forward_list_node<T>* head;

public:
    explicit forward_list(const Allocator& alloc = Allocator())
        : detail::forward_list_alloc_base<T, Allocator>(alloc), head(nullptr) {}

    ~forward_list() {
        clear();
    }

    iterator begin() {
        return iterator(head);
    }

    const_iterator begin() const {
        return const_iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator end() const {
        return const_iterator(nullptr);
    }

    bool empty() const {
        return head == nullptr;
    }

    size_type size() const {
        size_type count = 0;
        for (auto it = begin(); it != end(); ++it) {
            ++count;
        }
        return count;
    }

    void push_front(const T& val) {
        auto node = this->allocate_node(val);
        node->next = head;
        head = node;
    }

    void pop_front() {
        if (head) {
            auto next = head->next;
            this->deallocate_node(head);
            head = next;
        }
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }
};

int main() {
    forward_list<int> fl;
    fl.push_front(30);
    fl.push_front(20);
    fl.push_front(10);

    for (auto it = fl.begin(); it != fl.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}