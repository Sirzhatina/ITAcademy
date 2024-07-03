#pragma once

#include <cstdint>
#include <cstddef>

class Player {
public:
    Player();

    void addScores(std::int16_t scores);

    std::int16_t getScores() const;
    std::size_t getId() const;

private:
    std::int16_t m_scores = 0;

    std::size_t m_playerId;

    static inline std::size_t id_counter = 0;
};
