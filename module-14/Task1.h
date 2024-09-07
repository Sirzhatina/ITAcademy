#pragma once

#include <vector>
#include <string>
#include <ranges>

namespace hw14 {
    class Task1 {
    public:
        Task1() = default;

        int mainFlow();

    private:
        void printNumbers(const std::string& msg, std::ranges::view auto vecView) const;
        void printSum() const;

        static constexpr int factor = 2;

        std::vector<int> m_storedVec;
    };
}