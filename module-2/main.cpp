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
/**
    * @brief Creates new system info instance with data retrieved from the compiler
    * at preprocessing stage
    * @throw Same as std::format used internally
    * @return SystemInfo 
    */
SystemInfo makeSystemInfo();

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: program factorial_argument\n";
        return EXIT_FAILURE;
    }
    factorialTask(argc, argv);

    printSystemInfo(makeSystemInfo());
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

SystemInfo makeSystemInfo() {
    std::string osName = 
#ifdef __linux__
    "Linux"
#elif _WIN32
    "Windows"
#elif __APPLE__
    "Apple";
#elif __FreeBSD__
    "FreeBSD"
#elif __ANDROID__
    "Android"
#else
    "Unknown"
#endif 
    ; 
    
#ifdef __GNUC__
    auto compilerName = "GCC";
    auto compilerVersion = std::format("{}.{}.{}", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif __clang__
    auto compilerName = "Clang";
    auto compilerVersion = std::format("{}.{}.{}", __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif _MSC_VER
    auto compilerName = "MSVC";
    auto compilerVersion = std::format("{}", _MSC_VER);
#else
    auto compilerName = "Unknown";
    auto compilerVersion = "";
#endif

    return SystemInfo{osName, compilerName, compilerVersion};
}