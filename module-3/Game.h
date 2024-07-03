#pragma once

#include "Player.h"
#include <cstdint>
#include <functional>


class Game {
public:
    Game(std::size_t rounds = DEFAULT_NUMER_OF_ROUNDS, std::int16_t scoresTowin = DEFAULT_SCORES_TO_WIN);

    void mainLoop();
private:

    bool hasPlayerReachedScores(const Player& pl) const;
    void declareVictory(const Player& pl) const;
    bool isDraw() const;
    void declareDraw() const;
    void runOutOfRounds() const;

private:
    Player m_first, m_second;

    std::size_t m_numberOfRounds;
    std::int16_t m_scoresToWin;

    static std::function<std::int16_t()> m_generateNumber;

    static constexpr auto DEFAULT_NUMER_OF_ROUNDS = 100;
    static constexpr auto DEFAULT_SCORES_TO_WIN = 50;
};