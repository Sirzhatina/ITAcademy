#pragma once

#include <vector>
#include <random>

#include "utility/StreamChecker.h"

class VectorGenerator {
public:
    explicit VectorGenerator(std::size_t vecSize);

    void printVector(const std::string& msg);

    void generate();

    void sort();

private:

	std::vector<int> m_values;

    StreamChecker strchk{};


    std::random_device rd{};
    std::mt19937 mt{ rd() };
    std::uniform_int_distribution<int> distr{ 1, 100 };
};