#include <iostream>
#include <format>


/// @brief Prints in one line expressions separated by tabs 
/// with one operand variating from lowerBound to upperBound (exclusively)
/// in each expression, multiplied by constant operand as a second one
/// @param lowerBound - first operand of the expressions, each of which has it
/// incremented
/// @param upperBound - value to which lowerBound operand will exclusively be incrementing
/// @param factor - second operand of the expressions, stays the same for all of them
void printLine(int lowerBound, int upperBound, int factor);
/// @brief iteratively calls printLine() passing it its own arguments
/// and incrementing factor for each call from 1 to 10
/// @param lowerBound - parameter passed for internally called printLine()
/// and serving the same purpose as for that function
/// @param upperBound - same as lowerBound: internally passed for printLine()
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