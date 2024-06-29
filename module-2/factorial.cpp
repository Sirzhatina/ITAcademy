#include "factorial.hpp"

FACTORIAL_USED_TYPE factorial(FACTORIAL_USED_TYPE n) {
    FACTORIAL_USED_TYPE result = 1;

#ifdef RECURSIVE_FACTORIAL
    if (n < 1) {
        return 1;
    }
    return n * factorial(n - 1);
#else
    for (auto i{n}; i > 1; i--) {
        result *= i;
    }
    return result;
#endif
}
