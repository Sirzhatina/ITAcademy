#include <memory>
#include <iostream>
#include "utils.h"
#include "PointedArr.h"
#include "StreamChecker.h"


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

    StreamChecker strchk{};

    strchk.processStreamFailure(std::cout);
    strchk.processStreamFailure(std::cin);
}

int main(int argc, char* argv[])
{
    using namespace hw7;

    constexpr auto ARRAY_SIZE = 10;
    
    PointedArr pa{ 10 };
    inputElementsOf(pa);
    printElementsOf(pa);

    return 0;
}