#pragma once

#include <random>
#include <vector>

namespace hw14 {
    class VectorGenerator {
    public:
        VectorGenerator(int lower, int upper) : m_lowerBound{ lower }, m_upperBound{ upper } { }

        std::vector<int> operator()(const std::size_t size) const {
            std::vector<int> vec;
            vec.resize(size);

            static std::mt19937 mt{ std::random_device{}() };
            static std::uniform_int_distribution<int> distr{ m_lowerBound, m_upperBound };

            std::ranges::generate(vec, []() { return distr(mt); });
            return vec;
        }
    private:
        int m_lowerBound;
        int m_upperBound;
    };
}