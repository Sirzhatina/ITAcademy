#include "factorial.hpp"
#include <iostream>
#include <format>

#include <os_compiler.h>
#include "system_info.hpp"

int main(int argc, char* argv[])
{
    std::cout 
        << std::format("Factorial of 5 is: {}", factorial(5))
        << std::endl;

    std::cout << SystemInfo::makeSystemInfo();

    std::cout << SystemInfo::makeSystemInfoFromCustomSource(
        OS_NAME, 
        COMPILER_NAME, 
        COMPILER_VERSION
    );

    return 0;
}