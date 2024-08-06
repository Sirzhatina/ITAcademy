#pragma once

#include <cstring>
#include <algorithm>

namespace hw6 {
    class StringReverser;
}


/// @brief a simple class to take a c-style string from the standard input,
/// reverse it and print the passed string to the standard output
class hw6::StringReverser{
public:
    /// @brief default constructor
	StringReverser() = default;
    /// @brief method that places characters of the passed string in the reverse order
    /// @param str - pointer pointing to the beginning of an array of characters. The method doesn't
    /// produce any additional result and reorders characters in-place.
    void reverseString(char* str);
    /// @brief simple method to invite the user for input in the console
    /// and take that input as an array of chars. The method takes the destination pointer
    /// and the max size of this destination. If the number of characters 
    /// is greater than the maxSize, the out-of-range characters get trimmed. 
    /// If the maxSize argument is greater than the actual storage size,
    /// the behaviour is undefined. The string from the input 
    /// becomes null-terminated in the passed storage.
    /// @param inputStr - pointer to the destination to store characters from the standard input.
    /// @param maxSize - the maximum allowed number of characters to store.
    void takeUserInput(char* inputStr, const std::size_t maxSize);
    /// @brief method to print the message followed by the passed c-string.
    /// @param outputStr - a c-style null-terminated string to print.
    /// if the passed string isn't null-terminated, the behavoiur is undefined.
    void printString(char* outputStr);
};