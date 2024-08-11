#include <memory>
#include <iostream>
#include "utils.h"
#include "PointedArr.h"
#include "StreamChecker.h"
#include <optional>
#include <algorithm>
#include <numeric>

void inputElementsOf(std::shared_ptr<int[]> p, std::size_t sz);
void inputElementsOf(hw7::PointedArr& pa);

void printElementsOf(const std::shared_ptr<int[]> p, std::size_t sz);
void printElementsOf(const hw7::PointedArr& pa);

std::optional<int> sum(std::weak_ptr<int[]> wp, std::size_t sz);
std::optional<std::pair<int, int>> minmax(std::weak_ptr<int[]> wp, std::size_t sz);

int main(int argc, char* argv[])
{
    using namespace hw7;

    constexpr auto ARRAY_SIZE = 10;
    
    PointedArr pa{ 10 };
    inputElementsOf(pa);
    printElementsOf(pa);

    std::size_t sharedArraySize{};
    std::cout << "Enter the size of the shared array: ";
    std::cin >> sharedArraySize;

    auto shp = std::make_shared<int[]>(sharedArraySize);
    inputElementsOf(shp, sharedArraySize);

    
    if (auto s = sum(shp, sharedArraySize); s.has_value()) {
        itac::print("The sum of all elements is {}", s.value())
            << std::endl;
    }

    if (auto mm = minmax(shp, sharedArraySize); mm.has_value()) {
        itac::print(
            "Min element: {}; max element: {}", 
            mm.value().first, 
            mm.value().second
        ) << std::endl;
    }

    return 0;
}


void inputElementsOf(hw7::PointedArr& pa) {
    itac::print("Enter {} numbers: ", pa.getSize());

    for (std::size_t i = 0; i < pa.getSize(); ++i) {
        std::cin >> pa[i];
    }

    StreamChecker strchk{};

    strchk.processStreamFailure(std::cout);
    strchk.processStreamFailure(std::cin);
}


void printElementsOf(const hw7::PointedArr& pa) {
    itac::print("The numbers you've entered:");

    for (std::size_t i = 0; i < pa.getSize(); ++i) {
        itac::print(" {}", pa[i]);
    }
    std::cout << std::endl;

    StreamChecker strchk{};

    strchk.processStreamFailure(std::cout);
    strchk.processStreamFailure(std::cin);
}

void inputElementsOf(std::shared_ptr<int[]> p, std::size_t sz) {
    itac::print("Enter {} numbers: \n", sz);

    for (std::size_t i = 0; i < sz; ++i) {
        std::cin >> p[i];
    }
}

void printElementsOf(const std::shared_ptr<int[]> p, std::size_t sz) {
    std::cout << "Shared pointed array:";
    for (std::size_t i = 0; i < sz; ++i) {
        std::cout << ' ' << p[i];
    }
    std::cout << std::endl;
}

std::optional<int> sum(std::weak_ptr<int[]> wp, std::size_t sz) {

    if (auto p = wp.lock(); p != nullptr && sz != 0) {

        return std::accumulate(p.get(), p.get() + sz, 0);
    }
    return {};
}

std::optional<std::pair<int, int>> minmax(std::weak_ptr<int[]> wp, std::size_t sz) {

    if (auto p = wp.lock(); p != nullptr && sz != 0) {
        auto res = std::minmax_element(p.get(), p.get() + sz);
        return { std::pair{ *res.first, *res.second } };
    }
    return {};
}
