#include "number_parser.h"

#include <iostream>
#include <algorithm>
#include <format>

std::uint32_t input() {
    std::uint32_t result = 0;
    std::cout << "Enter the number: ";

    if (std::cin.peek() == '-') {
        std::cerr << "The positive number is expected";
        std::exit(EXIT_FAILURE);
    }
    
    std::cin >> result;
    if (!std::cin) {
        std::cerr << "Input failure.";
        std::exit(EXIT_FAILURE);
    }
    
    return result;
}

std::string parseNumber(std::uint32_t n) {
    std::string result;
    
    do {
        result += std::to_string(n % 10) + ' ';
        n /= 10;
    } while(n != 0);
    
    // pops the last whitespace
    result.pop_back();
    std::ranges::reverse(result);

    return result;
}

void mainParseNumberTask() {
    auto result = parseNumber(input());
    std::cout 
        << std::format("The result is: {}\n", result)
        << std::endl;
}