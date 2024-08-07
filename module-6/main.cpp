#include "StringReverser.h"
#include <iostream>
#include "utility/StreamChecker.h"
#include "VectorGenerator.h"

void mainTask1();
void mainTask2();

int main(int argc, char* argv[])
{
    mainTask1();
    std::cout << std::endl;

    mainTask2();
    std::cout << std::endl;

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

void mainTask2() {
    StreamChecker strchk{};

    std::size_t vectorSize = 0;
    std::cout << "Input the size of the vector: ";
    strchk.processStreamFailure(std::cout);
    std::cin >> vectorSize;
    strchk.processStreamFailure(std::cin);

    VectorGenerator vg{ vectorSize };

    vg.generate();

    vg.printVector("Vector unsorted: ");
    vg.sort();
    vg.printVector("Sorted vector: ");
}