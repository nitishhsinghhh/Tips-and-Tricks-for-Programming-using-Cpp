#ifndef ICOMPARATOR_HPP
#define ICOMPARATOR_HPP

#include <iostream>
#include <string>

/**
 * @interface IComparator
 * @brief Interface for comparing two characters.
 */
class IComparator {
public:
    virtual void compare(char a, char b) = 0;
    virtual ~IComparator() = default;
};

#endif