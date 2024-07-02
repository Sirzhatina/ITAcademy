#include "table.h"
#include "number_parser.h"
#include <chrono>
#include <cstdint>
#include <format>
#include <iostream>
#include <random>
#include <thread>

void declareDraw() {
    std::cout << "Noone has won. Bye\n";
}

int main()
{
    mainTableTask();
    mainParseNumberTask();

    std::cout << "\n--------------------------- NOW LET'S PLAY -------------------\n";

    std::int16_t player_1_scores = 0;
    std::int16_t player_2_scores = 0;

    auto gen = [
        mt = std::mt19937{ std::random_device{}() },
        distr = std::uniform_int_distribution{ -5, 5 }
    ]() mutable {
        return distr(mt); 
    };

    for (int i = 0; i < 100; ++i) {
        player_1_scores += gen();
        player_2_scores += gen();

        if (player_1_scores >= 50 && player_2_scores >= 50) {
            break;
        }
        else if (player_1_scores >= 50) {
            std::cout << "We've got the winner!" 
                << std::format(" Player 1 won. Earned scores are: {}", player_1_scores) 
                << std::endl;
            return 0;
        }
        else if (player_2_scores >= 50) {
            std::cout << "We've got the winner!" 
                << std::format(" Player 2 won. Earned scores are: {}", player_2_scores) 
                << std::endl;
            return 0;
        }

        if (i % 10 == 0) {
            std::cout 
                << std::format(
                    "Current round is: {}\n"
                    "Player 1 scores: {}\n"
                    "Player 2 scores: {}", 
                    i,
                    player_1_scores,
                    player_2_scores
                ) << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    declareDraw();

    return 0;
}
