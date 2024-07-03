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

class Player {
public:
    Player() = default;

    std::int16_t getScores() const { return m_scores; }
    void addScores(std::int16_t scores) { m_scores += scores; }

private:
    std::int16_t m_scores{0};
};

int main()
{
    mainTableTask();
    mainParseNumberTask();

    std::cout << "\n--------------------------- NOW LET'S PLAY -------------------\n";

    Player first{};
    Player second{};

    auto gen = [
        mt = std::mt19937{ std::random_device{}() },
        distr = std::uniform_int_distribution{ -5, 5 }
    ]() mutable {
        return distr(mt); 
    };

    for (int i = 0; i < 100; ++i) {
        first .addScores(gen());
        second.addScores(gen());

        if (first.getScores() >= 50 && second.getScores() >= 50) {
            break;
        }
        else if (first.getScores() >= 50) {
            std::cout << "We've got the winner!" 
                << std::format(" Player 1 won. Earned scores are: {}", first.getScores()) 
                << std::endl;
            return 0;
        }
        else if (second.getScores() >= 50) {
            std::cout << "We've got the winner!" 
                << std::format(" Player 2 won. Earned scores are: {}", second.getScores())
                << std::endl;
            return 0;
        }

        if (i % 20 == 0) {
            std::cout 
                << std::format(
                    "Current round is: {}\n"
                    "Player 1 scores: {}\n"
                    "Player 2 scores: {}", 
                    i,
                    first.getScores(),
                    second.getScores()
                ) << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    declareDraw();

    return 0;
}
