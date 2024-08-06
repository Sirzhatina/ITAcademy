#include "StringReverser.h"

int main(int argc, char* argv[])
{
    constexpr auto DEFAULT_STRING_SIZE    = 99;
    constexpr auto NULL_TERMINATED_STRING_SIZE = DEFAULT_STRING_SIZE + 1;

    char infoString[NULL_TERMINATED_STRING_SIZE];

    hw6::StringReverser strRev{};

    strRev.takeUserInput(infoString, DEFAULT_STRING_SIZE);
    strRev.reverseString(infoString);
    strRev.printString(infoString);
    
    return 0;
}