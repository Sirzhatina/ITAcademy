#include <charconv>
#include <cstdlib>
#include <iostream>
#include <format>
#include <stdexcept>
#include <system_error>

#include <os_compiler.h>

#include "factorial.hpp"
#include "system_info.hpp"

void factorialTask(int argc, char* argv[]);

void printSystemInfo(const SystemInfo& sys);

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: program factorial_argument\n";
        return EXIT_FAILURE;
    }
    factorialTask(argc, argv);

    printSystemInfo(SystemInfo::makeSystemInfo());
    printSystemInfo(SystemInfo{
        OS_NAME,
        COMPILER_NAME,
        COMPILER_VERSION
    });

    return 0;
}

void factorialTask(int argc, char* argv[]) {
    FACTORIAL_USED_TYPE value{};

    auto [_, ec] = std::from_chars(argv[1], argv[2] - 1, value);
    if (ec == std::errc::invalid_argument) {
        std::cerr << "Number given is not valid!";
        std::exit(EXIT_FAILURE);
    }
    try {
        std::cout 
            << std::format("Factorial of {} is: {}\n", value, factorial(value))
            << std::endl;
    } catch (const std::logic_error& le) {
        std::cerr << le.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
}

void printSystemInfo(const SystemInfo& sys) {
    std::cout << std::format(
        "OS name: {}\n"
        "Compiler name: {}\n"
        "Compiler version: {}\n",
        sys.getOsName(),
        sys.getCompilerName(),
        sys.getCompilerVersion()
    ) << std::endl;
}