#include "StringReverser.h"
#include <iostream>
#include "utility/StreamChecker.h"
#include <random>
#include <vector>
#include <algorithm>

void mainTask1();

int makeValue() {
    static auto rd = std::random_device{};
    static auto mt = std::mt19937{ rd() };
    static auto distr = std::uniform_int_distribution{ 1, 6 };

    return distr(mt);
}

static StreamChecker strchk{};

void printVector(const std::vector<int>& vec, const std::string& msg) {
    std::cout << msg;
    std::ranges::copy(vec, std::ostream_iterator<int>{ std::cout, " " });
    std::cout << std::endl;
    strchk.processStreamFailure(std::cout);
}


int main(int argc, char* argv[])
{
    mainTask1();
    std::cout << std::endl;

    namespace rng = std::ranges;

    std::size_t vectorSize = 0;
    std::cout << "Input the size of the vector: ";
    strchk.processStreamFailure(std::cout);
    std::cin >> vectorSize;
    strchk.processStreamFailure(std::cin);

    std::vector<int> values(vectorSize);
    rng::generate(values, makeValue);

    printVector(values, "Vector unsorted: ");
    rng::sort(values);
    printVector(values, "Sorted vector: ");
    return 0;
}


void mainTask1() {
    constexpr auto DEFAULT_STRING_SIZE = 99;
    constexpr auto NULL_TERMINATED_STRING_SIZE = DEFAULT_STRING_SIZE + 1;

    char infoString[NULL_TERMINATED_STRING_SIZE];

    hw6::StringReverser strRev{};

    strRev.takeUserInput(infoString, DEFAULT_STRING_SIZE);
    strRev.reverseString(infoString);
    strRev.printString(infoString);
}
