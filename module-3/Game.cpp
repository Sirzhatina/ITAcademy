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
    std::size_t roundsPlayed = 0;
    for (; roundsPlayed < m_numberOfRounds; ++roundsPlayed) {
        m_first.addScores(m_generateNumber());
        m_second.addScores(m_generateNumber());

        if (isDraw()) {
            declareDraw();
            break;
        }
        else if (hasPlayerReachedScores(m_first)) {
            declareVictory(m_first);
            break;
        }
        else if (hasPlayerReachedScores(m_second)) {
            declareVictory(m_second);
            break;
        }

        if (roundsPlayed % 20 == 0) {
            std::cout 
                << std::format(
                    "Current round is: {}\n"
                    "\tPlayer 1 scores: {}\n"
                    "\tPlayer 2 scores: {}", 
                    roundsPlayed,
                    m_first.getScores(),
                    m_second.getScores()
                ) << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (roundsPlayed >= m_numberOfRounds) {
        runOutOfRounds();
    }
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