#include "Dependency.hpp"
#include <iostream>

class ConcreteDependency : public Dependency<ConcreteDependency> {
public:
    void implementation() {
        // Implementation of the interface
        std::cout << "ConcreteDependency implementation called!" << std::endl;
    }
};

