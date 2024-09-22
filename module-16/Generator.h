#pragma once

#include <random>

static std::mt19937 mt{ std::random_device{}() };

class Generator {
public:
    Generator(int min, int max) : m_distr{ min, max } { }

    template <template <class> class Container>
    Container<int> generate(std::size_t size) {
        Container<int> result;
        result.resize(size);

        std::ranges::generate(result, [this]() { return m_distr(mt); });

        return result;
    }

private:
    std::uniform_int_distribution<int> m_distr;
};