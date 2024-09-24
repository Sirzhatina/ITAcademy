#pragma once

#include <algorithm>
#include <iterator>
#include <format>
#include <iostream>
#include "Data.h"

template <class C>
void print(const std::string& msg, const C& c) {
    std::cout << msg;
    std::ranges::copy(c, std::ostream_iterator<typename C::value_type>{std::cout, " "});
    std::cout << std::endl;
}

template <int size>
void printData(const std::string& msg, const std::array<Data, size>& d) {
    std::cout << msg << '\n';
    for (const auto& [id, value] : d) {
        std::cout << std::format("({}; {})\n", id, value);
    }
    std::cout << std::endl;
}
