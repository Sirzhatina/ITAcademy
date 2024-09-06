#include <vector>
#include <ranges>
#include <algorithm>
#include <random>
#include <iostream>
#include <numeric>

std::vector<int> generateVector(const std::size_t size) {
    
    std::vector<int> vec;
    vec.resize(size);

    static std::mt19937 mt{ std::random_device{}() };
    static std::uniform_int_distribution<int> distr{ 10, 50 };

    std::ranges::generate(vec, []() { return distr(mt); });
    return vec;
}

int main(int argc, char* argv[])
{
    auto myVec = generateVector(10);

    auto printEvenOf = [](const std::vector<int>& vec) {
        std::ranges::copy_if(
            vec, 
            std::ostream_iterator<int>{std::cout, " "}, 
            [](auto val) { return val % 2 == 0; }
        );
    };

    auto sumVector = [](const std::vector<int>& vec) {
        return std::accumulate(std::begin(vec), std::end(vec), 0);
    };

    int factor = 2;

    auto multiplyValuesOf = [factor](std::vector<int>& vec) {
        for (auto& val : vec) {
            val *= factor;
        }
        return vec;
    };

    std::cout << "The printed even numbers: ";
    printEvenOf(myVec);
    std::cout << std::endl;

    std::cout << "Sum of the vector: " << sumVector(myVec) << std::endl;

    std::cout << "Multiplied vector: ";
    std::ranges::copy(multiplyValuesOf(myVec), std::ostream_iterator<int>{std::cout, " "});

    return 0;
}