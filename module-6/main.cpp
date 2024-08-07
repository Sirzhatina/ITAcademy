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

    constexpr auto SQUARE_MATRIX_SIZE = 3;

    int** mtx = new int*[SQUARE_MATRIX_SIZE];

    for (int i = 0; i < SQUARE_MATRIX_SIZE; ++i) {
        mtx[i] = new int[SQUARE_MATRIX_SIZE];
        for (int j = 0; j < SQUARE_MATRIX_SIZE; ++j) {
            mtx[i][j] = i * j;
        }
    }
    std::cout << "The matrix:\n";
    for (int i = 0; i < SQUARE_MATRIX_SIZE; ++i) {
        for (int j = 0; j < SQUARE_MATRIX_SIZE; ++j) {
            std::cout << mtx[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << std::endl;

    for (int i = 0; i < SQUARE_MATRIX_SIZE; ++i) {
        delete mtx[i];
    }

    delete mtx;
    mtx = nullptr;

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