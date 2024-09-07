#include "Task1.h"
#include "VectorGenerator.h"
#include <iostream>
#include <numeric>

namespace hw14 {
    int Task1::mainFlow() {
        VectorGenerator gen{ 10, 50 };
        m_storedVec = gen(10);

        printNumbers("The even numbers: ", m_storedVec | std::views::filter([](auto n) { return n % 2 == 0; }));

        printNumbers(
            "Multiplied numbers: ",
            m_storedVec | std::views::transform([this](auto n) { return n * this->factor; })
        );

        printSum();

        return 0;
    }

    void Task1::printNumbers(const std::string& msg, std::ranges::view auto vecView) const {

        auto printEvenOf = [](decltype(vecView) rng) {
            std::ranges::copy(rng, std::ostream_iterator<int>{std::cout, " "});
        };

        std::cout << msg;
        printEvenOf(vecView);
        std::cout << std::endl;
    }
    void Task1::printSum() const {
        auto sumVector = [](const std::vector<int>& vec) {
            return std::accumulate(std::begin(vec), std::end(vec), 0);
        };
        std::cout << "Sum of the vector: " << sumVector(m_storedVec) << std::endl;
    }
}

