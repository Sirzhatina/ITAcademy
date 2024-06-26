#include "compiler_info.hpp"

#include <iostream>
#include <string>
#include <format>

void compilerInfo() {
    std::string output = std::format("Compiler: "
#ifdef __GNUC__
    "GCC {}.{}.{}", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__
#elif defined(__clang__)
    "Clang {}.{}.{}", __clang_major__, __clang_minor__, __clang_patchlevel__
#elif defined(_MSC_VER)
    "{}", _MSC_VER
#else
    "Unknown"
#endif
    );
    std::cout << output << std::endl;
}