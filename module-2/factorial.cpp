#include "factorial.hpp"

FACTORIAL_USED_TYPE factorial(FACTORIAL_USED_TYPE n) {
    FACTORIAL_USED_TYPE result = 1;

    for (auto i{n}; i > 1; i--) {
        result *= i;
    }
    return result;
}