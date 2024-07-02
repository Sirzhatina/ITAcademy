#include <iostream>
#include <format>

void printLine(int lowerBound, int upperBound, int factor);

void printColumns(int lowerBound, int upperBound);

int main(int argc, char* argv[])
{
    std::cout << "\t\tMULTIPLICATION TABLE\n";
    printColumns(2, 6);
    std::cout << std::endl;
    printColumns(6, 10);
    return 0;
}


void printLine(int lowerBound, int upperBound, int factor) {
    while (lowerBound < upperBound) {
        std::cout
            << std::format("{} x {:2} = {:2}\t", lowerBound, factor, lowerBound * factor);
        ++lowerBound;
    }
}

void printColumns(int lowerBound, int upperBound) {
    for (int i = 1; i <= 10; ++i) {
        printLine(lowerBound, upperBound, i);
        std::cout << '\n';
    }
}