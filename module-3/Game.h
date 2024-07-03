#pragma once

#include <cstdint>
#include <functional>

class Player {
public:
    Player()
    // decided to avoid id 0, let players be counted from 1
    : m_playerId{++id_counter}
    {}

    std::int16_t getScores() const { return m_scores; }
    void addScores(std::int16_t scores) { m_scores += scores; }

    std::size_t getId() const { return m_playerId; }

private:
    std::int16_t m_scores = 0;

    std::size_t m_playerId;

    static inline std::size_t id_counter = 0;
};

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