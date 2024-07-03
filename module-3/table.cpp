#include "table.h"
#include <iostream>
#include <format>

void printLine(int lowerBound, const int upperBound, const int factor) {
    while (lowerBound < upperBound) {
        std::cout
            << std::format("{} x {:2} = {:2}\t", lowerBound, factor, lowerBound * factor);
        ++lowerBound;
    }
}

void printColumns(int lowerBound, const int upperBound) {
    for (int i = 1; i <= 10; ++i) {
        printLine(lowerBound, upperBound, i);
        std::cout << '\n';
    }
}

void mainTableTask() {
    std::cout << "\t\tMULTIPLICATION TABLE\n";
    printColumns(2, 6);
    std::cout << std::endl;
    printColumns(6, 10);
}