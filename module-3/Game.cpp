#include "Game.h"
#include <cstdint>
#include <functional>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>

Game::Game(std::size_t rounds, std::int16_t scoresTowin)
: m_numberOfRounds{rounds}
, m_scoresToWin{scoresTowin}
{
}

void Game::mainLoop() {
    for (std::size_t i = 0; i < m_numberOfRounds; ++i) {
        m_first.addScores(m_generateNumber());
        m_second.addScores(m_generateNumber());

        if (isDraw()) {
            declareDraw();
            return;
        }
        else if (hasPlayerReachedScores(m_first)) {
            declareVictory(m_first);
            return;
        }
        else if (hasPlayerReachedScores(m_second)) {
            declareVictory(m_second);
            return;
        }

        if (i % 20 == 0) {
            std::cout 
                << std::format(
                    "Current round is: {}\n"
                    "Player 1 scores: {}\n"
                    "Player 2 scores: {}", 
                    i,
                    m_first.getScores(),
                    m_second.getScores()
                ) << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    runOutOfRounds();
}

bool Game::hasPlayerReachedScores(const Player& pl) const {
    return pl.getScores() >= m_scoresToWin;
}

void Game::declareVictory(const Player& pl) const {
    std::cout << "We've got the winner!" 
        << std::format(" Player {} won. Earned scores are: {}", pl.getId(), pl.getScores()) 
        << std::endl;
}

bool Game::isDraw() const { 
    return m_first.getScores() >= m_scoresToWin && m_second.getScores() >= m_scoresToWin; 
}

void Game::declareDraw() const {
    std::cout << "Noone has won. Bye\n";
}

void Game::runOutOfRounds() const {
    std::cout << "All rounds are played.\n";
    declareDraw();
}


std::function<std::int16_t()> Game::m_generateNumber = [
    mt = std::mt19937{ std::random_device{}() },
    distr = std::uniform_int_distribution{ -5, 5 }
]() mutable {
    return distr(mt); 
};