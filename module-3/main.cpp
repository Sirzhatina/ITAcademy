#include "table.h"
#include "number_parser.h"
#include "Game.h"
#include <iostream>

int main()
{
    mainTableTask();
    mainParseNumberTask();

    std::cout << "\n--------------------------- NOW LET'S PLAY -------------------\n";

    Game g;
    g.mainLoop();

    return 0;
}
