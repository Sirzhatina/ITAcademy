#pragma once

#include <cstdint>
#include <cstddef>

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
