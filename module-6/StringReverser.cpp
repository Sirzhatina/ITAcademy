#include "StringReverser.h"

#include <iostream>
#include <cstring>
#include <format>

using namespace hw6;

void StringReverser::reverseString(char* str) {
    if (str == nullptr) {
        return;
    }
    std::size_t end = std::strlen(str);
    --end;

    for (std::size_t start = 0; start < end; ++start, --end) {
        std::swap(str[start], str[end]);
    }
}

void StringReverser::takeUserInput(char* inputStr, const std::size_t maxSize) {
    std::cout
        << std::format("Enter the string (up to {} characters, the rest will be left): ", maxSize);
    std::cin.getline(inputStr, maxSize);
}

void StringReverser::printString(char* outputStr) {
    std::cout
        << "Entered string reversed: "
        << outputStr
        << std::endl;
}