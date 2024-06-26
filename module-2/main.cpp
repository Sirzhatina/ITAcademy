#include "factorial.hpp"
#include <iostream>
#include <format>

int main(int argc, char* argv[])
{
    std::cout 
        << std::format("Factorial of 5 is: {}", factorial(5))
        << std::endl;
    return 0;
}