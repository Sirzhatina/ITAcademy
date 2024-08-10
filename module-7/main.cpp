#include <memory>
#include <iostream>
#include <format>
#include <string>
#include "utils.h"


template <class T>
using UPtr = std::unique_ptr<T>;

UPtr<int[]> initUPtrArray(const std::size_t size) {
    return std::make_unique<int[]>(size);
}

UPtr<int[]> inputArray(UPtr<int[]> p, std::size_t sz) {
    itac::print("Enter {} numbers: ", sz);
    
    for (std::size_t i = 0; i < sz; ++i) {
        std::cin >> p[i];
    }

    return p;
}


UPtr<int[]> printUPtrArray(UPtr<int[]> p, const std::size_t sz) {
    itac::print("The numbers you've entered:");
    for (std::size_t i = 0; i < sz; ++i) {
        itac::print(" {}", p[i]);
    }

    return p;
}

int main(int argc, char* argv[])
{
    constexpr auto ARRAY_SIZE = 10;

    auto arr = initUPtrArray(ARRAY_SIZE);

    arr = inputArray(std::move(arr), ARRAY_SIZE);

    arr = printUPtrArray(std::move(arr), ARRAY_SIZE);

    

    return 0;
}