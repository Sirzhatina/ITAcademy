#include "number_converter.h"

int main(int argc, char* argv[])
{

    NumberConverter nc{};
    nc.userInput();
    nc.printNumber(nc.currentNumber());
    nc.printNumber(nc.convertValue());
    return 0;
}