#include <memory>
#include <iostream>
#include "utils.h"
#include "PointedArr.h"
#include "StreamChecker.h"


int main(int argc, char* argv[])
{
    using namespace hw7;

    constexpr auto ARRAY_SIZE = 10;
    
    PointedArr<std::unique_ptr> pa{ ARRAY_SIZE };
    inputElementsOf(pa);
    printElementsOf(pa);

    std::size_t sharedArraySize{};
    std::cout << "Enter the size of the shared array: ";
    std::cin >> sharedArraySize;

    auto sp = std::make_shared<int[]>(sharedArraySize);

    PointedArr<std::weak_ptr> wp{ sp, sharedArraySize };
    inputElementsOf(wp);

    if (auto sum = wp.sum(); sum.has_value()) {
        itac::print("The sum of all elements is {}", sum.value())
            << std::endl;
    }

    if (auto mm = wp.minmax(); mm.has_value()) {
        itac::print(
            "Min element: {}; max element: {}", 
            mm.value().first, 
            mm.value().second
        ) << std::endl;
    }

    return 0;
}


