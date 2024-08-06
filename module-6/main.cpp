#include <cstddef>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <format>

void reverseString(char* str) {
    if (str == nullptr) {
        return;
    }
    std::size_t end = std::strlen(str);
    --end;

    for (std::size_t start = 0; start < end; ++start, --end) {
        std::swap(str[start], str[end]);
    }
}


void takeUserInput(char* inputStr, const std::size_t maxSize) {
    std::cout
        << std::format("Enter the string (up to {} characters, the rest will be left): ", maxSize);
    std::cin.getline(inputStr, maxSize);
}

void printString(char* outputStr) {
    std::cout 
        << "Entered string reversed: " 
        << outputStr
        << std::endl;
}

int main(int argc, char* argv[])
{
    constexpr auto DEFAULT_STRING_SIZE    = 99;
    constexpr auto NULL_TERMINATED_STRING_SIZE = DEFAULT_STRING_SIZE + 1;

    char infoString[NULL_TERMINATED_STRING_SIZE];

    takeUserInput(infoString, DEFAULT_STRING_SIZE);
    reverseString(infoString);
    printString(infoString);

    return 0;
}