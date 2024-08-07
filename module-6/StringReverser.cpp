#include "StringReverser.h"

#include <cstring>


using namespace hw6;

StringReverser::StringReverser(char* str) : m_str{str} { }

void StringReverser::reverseString() {
    if (m_str == nullptr) {
        return;
    }
    std::size_t end = std::strlen(m_str) - 1;

    for (std::size_t start = 0; start < end; ++start, --end) {
        std::swap(m_str[start], m_str[end]);
    }
}

char* const StringReverser::getString() const {
    return m_str;
}
