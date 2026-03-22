// CRTP (Curiously Recurring Template Pattern) Base class
template <typename Derived>
class Dependency {
public:
    void interface() {
        // Call the implementation in the derived class
        static_cast<Derived*>(this)->implementation();
    }
};