#pragma once

#include <random>
#include <ranges>

class Generator {
    static inline std::mt19937 gen{ std::random_device{}() };
public:
    Generator(int min, int max) : m_distr{ min, max } { }

    template <template <class> class Container, std::integral T = int>
    requires 
        std::ranges::range<Container<T>>
    Container<T> generate(std::size_t size) {
        Container<T> result;
        result.resize(size);

        std::ranges::generate(result, [this]() { return m_distr(gen); });

        return result;
    }

private:
    
    std::uniform_int_distribution<int> m_distr;
};