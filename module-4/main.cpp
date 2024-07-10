#include "number_converter.hpp"

int main(int argc, char* argv[])
{

    NumberConverter nc{};
    nc.userInput();
    nc.printNumber(nc.currentNumber());
    nc.printNumber(nc.convertValue());
    return 0;
}