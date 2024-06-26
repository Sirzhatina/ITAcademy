#include "os_info.hpp"

#include <iostream>
#include <string>

void osInfo() {
    std::string output = "You're on ";

#ifdef __linux__
    output += "Linux";
#elif _WIN32
    output += "Windows";
#elif __APPLE__
    output += "Apple";
#elif __FreeBSD__
    output += "FreeBSD";
#else
    output += "...I don't know what you're on";
#endif

    std::cout << output << std::endl;
}