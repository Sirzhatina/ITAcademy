#pragma once

#include <cstring>
#include <algorithm>

namespace hw6 {
    class StringReverser;
}

class hw6::StringReverser{
public:
	StringReverser() = default;

    void reverseString(char* str);

    void takeUserInput(char* inputStr, const std::size_t maxSize);

    void printString(char* outputStr);
};