#pragma once

#include "utility/StreamChecker.h"

namespace hw6 {
    class StringReverser;
}


/// @brief a simple class to store a c-style string and reverse it
class hw6::StringReverser{
public:
    /// @brief constructor taking the pointer to c-style string.
    /// @param str - a pointer to a stack-allocated null-terminated string
    StringReverser(char* str);
    /// @brief method that places characters of the passed string in the reverse order.
    /// The method reverses the order of the internally stored string.
    void reverseString();
    /// @brief c-string getter.
    /// @return pointer to the beginning of the immutable c-style string.
    char* const getString() const;

private:
    StreamChecker m_streamChecker;

    char* m_str;
};