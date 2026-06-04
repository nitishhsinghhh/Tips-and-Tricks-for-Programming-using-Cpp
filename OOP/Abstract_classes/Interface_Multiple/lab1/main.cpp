#include <iostream>
#include <variant>
#include <vector>

using std::cout;
using std::endl;

// Completely flat, unlinked classes with no common base type
class Cat {
public:
    ~Cat() { cout << "Cat cleaned up from stack." << endl; }
    void makeSound() const { cout << "Meow!" << endl; }
};

class Dog {
public:
    ~Dog() { cout << "Dog cleaned up from stack." << endl; }
    void makeSound() const { cout << "Woof!" << endl; }
};

// Compile-time variant definition 
using PetVariant = std::variant<Cat, Dog>;

// Pattern matching visitor handler
struct PetSoundVisitor {
    void operator()(const Cat& cat) const { cat.makeSound(); }
    void operator()(const Dog& dog) const { dog.makeSound(); }
};

int main() {
    // Allocation happens completely sequentially in a single contiguous block
    std::vector<PetVariant> room;
    room.push_back(Cat{});
    room.push_back(Dog{});

    // Compile-time binding resolves the types safely via index tracking
    for (const auto& pet : room) {
        std::visit(PetSoundVisitor{}, pet);
    }

    return 0; // Everything is automatically and sequentially destroyed here
}