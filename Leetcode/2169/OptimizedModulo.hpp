#ifndef OPTIMIZED_MODULO_HPP
#define OPTIMIZED_MODULO_HPP

class OptimizedModuloSolution {
public:
    int countOperations(int num1, int num2) {
        int operations = 0;

        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                operations += num1 / num2;
                num1 %= num2;
            } else {
                operations += num2 / num1;
                num2 %= num1;
            }
        }

        return operations;
    }
};

#endif