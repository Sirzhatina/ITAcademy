#include "VectorGenerator.h"

#include <iostream>
#include <algorithm>
VectorGenerator::VectorGenerator(std::size_t vecSize) : m_values(vecSize) { }

void VectorGenerator::printVector(const std::string& msg) {
    std::cout << msg;
    std::ranges::copy(m_values, std::ostream_iterator<int>{ std::cout, " " });
    std::cout << std::endl;
    strchk.processStreamFailure(std::cout);
}

void VectorGenerator::generate() {
    std::ranges::generate(m_values, [this] { return distr(mt); });
}

void VectorGenerator::sort() { std::ranges::sort(m_values); }