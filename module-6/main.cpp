#include "StringReverser.h"
#include <iostream>
#include <format>
#include "utility/StreamChecker.h"
#include "VectorGenerator.h"
#include "SquareMatrix.h"

void mainTask1();
void mainTask2();
void mainTask3();

static StreamChecker strchk{};

int main(int argc, char* argv[])
{
    mainTask1();
    std::cout << std::endl;

    mainTask2();
    std::cout << std::endl;

    mainTask3();
    std::cout << std::endl;

    return 0;
}


void mainTask1() {
    constexpr auto DEFAULT_STRING_SIZE = 99;
    constexpr auto NULL_TERMINATED_STRING_SIZE = DEFAULT_STRING_SIZE + 1;

    char infoString[NULL_TERMINATED_STRING_SIZE];

    std::cout
        << std::format("Enter the string (up to {} characters, the rest will be left): ", DEFAULT_STRING_SIZE);
    strchk.processStreamFailure(std::cout);

    std::cin.getline(infoString, DEFAULT_STRING_SIZE);
    strchk.processStreamFailure(std::cin);

    hw6::StringReverser strRev{infoString};
    strRev.reverseString();

    std::cout
        << "Entered string reversed: "
        << strRev.getString()
        << std::endl;
    strchk.processStreamFailure(std::cout);
}

void mainTask2() {
    StreamChecker strchk{};


    std::size_t vectorSize = 0;
    std::cout << "Input the size of the vector: ";
    strchk.processStreamFailure(std::cout);
    std::cin >> vectorSize;
    strchk.processStreamFailure(std::cin);

    hw6::VectorGenerator vg{ vectorSize };

    vg.generate();

    vg.printVector("Vector unsorted: ");
    vg.sort();
    vg.printVector("Sorted vector: ");
}

void mainTask3() {
    hw6::SquareMatrix mtx{ 3 };
    mtx.generate();
    mtx.printMatrix();
}