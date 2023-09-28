// Forward declaration of the forward_list class template
template<class T, class Allocator = std::allocator<T>>
class forward_list;

namespace detail {

    // Helper class for managing the linked list nodes
    template<class T>
    struct forward_list_node {
        T value;                          // Value stored in the node
        forward_list_node<T>* next;       // Pointer to the next node
        forward_list_node(const T& val) : value(val), next(nullptr) {}
    };

    // Helper class for managing memory allocation
    template<class T, class Allocator>
    struct forward_list_alloc_base {
        using allocator_type = Allocator;
        allocator_type allocator;        // Allocator object

        forward_list_alloc_base(const Allocator& alloc) : allocator(alloc) {}

        // Allocate memory for a new node
        forward_list_node<T>* allocate_node(const T& val) {
            return allocator.allocate(1);
        }

        // Deallocate memory for a node
        void deallocate_node(forward_list_node<T>* node) {
            allocator.deallocate(node, 1);
        }
    };

    // Iterator class for forward_list
    template<class T, class Pointer, class Reference>
    struct forward_list_iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = Pointer;
        using reference = Reference;

        forward_list_node<T>* node;    // Pointer to the current node

        explicit forward_list_iterator(forward_list_node<T>* n) : node(n) {}

        // Iterator operations
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

// Class template for std::forward_list
template<class T, class Allocator>
class forward_list : private detail::forward_list_alloc_base<T, Allocator> {
public:
    // Public type aliases
    using value_type = T;
    using allocator_type = Allocator;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
    using iterator = detail::forward_list_iterator<T, pointer, reference>;
    using const_iterator = detail::forward_list_iterator<T, const_pointer, const_reference>;
    using size_type = std::size_t;

private:
    // Private data members
    detail::forward_list_node<T>* head;    // Pointer to the head node

public:
    // Constructor
    explicit forward_list(const Allocator& alloc = Allocator()) : detail::forward_list_alloc_base<T, Allocator>(alloc), head(nullptr) {}

    // Destructor
    ~forward_list() {
        clear();
    }

    // Iterator functions
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

    // Capacity
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

    // Modifiers
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

