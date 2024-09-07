#include <vector>
#include <ranges>
#include <algorithm>
#include <random>
#include <iostream>
#include "Task1.h"


int main(int argc, char* argv[])
{
    hw14::Task1 t1{};
    if (auto code = t1.mainFlow(); code != 0) {
        return code;
    }

    return 0;
}