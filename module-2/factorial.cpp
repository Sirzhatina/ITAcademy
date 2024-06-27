#include "factorial.hpp"

FACTORIAL_USED_TYPE factorial(FACTORIAL_USED_TYPE n) {
    FACTORIAL_USED_TYPE result = 1;

    for (auto i{n}; i > 1; i--) {
        result *= i;
    }
    return result;
}

FACTORIAL_USED_TYPE factRecurse(FACTORIAL_USED_TYPE n) {
    if (n < 1) {
        return 1;
    }
    return n * factRecurse(n - 1);
}