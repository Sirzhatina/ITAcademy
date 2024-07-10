#include "number_converter.h"

#include <cstdlib>
#include <iostream>
#include <format>

void NumberConverter::userInput() {
    std::cout << "Enter the number: ";
    std::cin >> m_userNumber;

    if (!std::cin) {
        std::cerr << "Input failure.";
        std::exit(EXIT_FAILURE);
    }

    m_isSet = true;
}

bool NumberConverter::isSet() const  { return m_isSet; }

void NumberConverter::reset() { m_isSet = false; }

void NumberConverter::printNumber(int number) const {
    std::cout << std::format(
        "The number given: {}\n"
        "Binary representation of this number: {}\n",
        number,
        AsBinary(number).to_string()
    ) << std::endl;
}

int NumberConverter::convertValue() const {
    if (!isSet()) {
        std::cout << "Warning: the internal value for conversion isn't set." << std::endl;
    }
    return (m_userNumber > 0 && (m_userNumber & 1) == 0) ? m_userNumber << 2 : m_userNumber >> 2;
}

int NumberConverter::currentNumber() const {
    return m_userNumber;
}