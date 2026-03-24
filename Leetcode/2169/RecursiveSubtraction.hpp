#ifndef RECURSIVE_SUBTRACTION_HPP
#define RECURSIVE_SUBTRACTION_HPP

class RecursiveSubtractionSolution {
public:
    int countOperations(int num1, int num2, int operation = 0) {
        if (num1 == 0 || num2 == 0) {
            return operation;
        }

        if (num1 >= num2) {
            return countOperations(num1 - num2, num2, operation + 1);
        }

        return countOperations(num1, num2 - num1, operation + 1);
    }
};

#endif