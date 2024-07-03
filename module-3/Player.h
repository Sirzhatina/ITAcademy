#pragma once

#include <cstdint>
#include <cstddef>

/// @brief Class to track information about the player.
/// Main attrubites are the numbers of earned scores and player's ID.
/// The latter is unique and increments starting from zero for each new
/// player.
class Player {
public:
    /// @brief Default constructor for Player.
    /// instantiates with scores equal to zero
    /// and an ID unique for each created object.
    Player();
    /// @brief saves the sum of passed scores and
    /// already stored ones rewriting the latter
    /// @param scores are added to the currently stored scores
    void addScores(std::int16_t scores);
    /// @brief method to get the value of the current scores
    /// @return the current player's scores
    std::int16_t getScores() const;
    /// @brief method to get the player's ID
    /// @return player's ID
    std::size_t getId() const;

private:
    std::int16_t m_scores = 0;

    std::size_t m_playerId;

    static inline std::size_t id_counter = 0;
};
