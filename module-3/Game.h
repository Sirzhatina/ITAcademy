#pragma once

#include "Player.h"
#include <cstdint>
#include <functional>

/// @brief the main game class. In essence, the game 
/// randomly generates a number for each player and adds it to their current scores. 
/// The winner is the one who first gets the set amount of scores (50 by default).
/// After the number of rounds played hits the limit (100 by default) if none of the players has
/// reached necessary scores, the draw is declared. The Game class
/// is responsible for initializing players and other attributes required by rules, 
/// handling the game loop, in which the state changing is happening mostly,
/// and declaring the winner afterwards.
class Game {
public:
    /// @brief Inits players and sets the numbers of scores to reach and rounds to play
    /// @param round the number of rounds to play before the draw will be declared.
    /// If not passed, the internal constant is used by default.
    /// @param scoresToWin the number of scores to earn for victory.
    /// If not passed, the internal constant is used by default.
    Game(std::size_t rounds = DEFAULT_NUMER_OF_ROUNDS, std::int16_t scoresTowin = DEFAULT_SCORES_TO_WIN);

    /// @brief method where the whole game process is happening.
    /// It generates on each iteration a random number for each player
    /// and sees who's hit the required minimum of scores. If both have
    /// in the same iteration, the draw is declared.
    void mainLoop();
private:

    /// @brief method telling whether the player hits the needed scores.
    /// @param pl player needed to be checked.
    /// @return true if the player's scores are not less than necessary,
    /// false otherwise.
    bool hasPlayerReachedScores(const Player& pl) const;
    /// @brief prints to the standard output information about the winning player.
    /// The method doesn't make any assumptions about whether passed player truly won or not,
    /// it just prints the text. Passing the right player is user's responsibility.
    /// @param pl the player about which the method is printing.
    void declareVictory(const Player& pl) const;
    /// @brief tells whether two players hits the bar of necessary number of scores.
    /// @return true if both players have not less score than needed to win, false otherwise.
    bool isDraw() const;
    /// @brief prints the info to the standard output saying that the draw has happened.
    /// This method doesn't make any assumptions about real game state.
    /// So, it's user's responsibility to call in in the right place.
    void declareDraw() const;
    /// @brief print to the standard output that all rounds are played and 
    /// the winner hasn't shown up, so it's a draw.
    /// This method doesn't make any assumptions about real game state.
    /// So, it's user's responsibility to call in in the right place.
    void runOutOfRounds() const;

private:
    Player m_first, m_second;

    std::size_t m_numberOfRounds;
    std::int16_t m_scoresToWin;

    static std::function<std::int16_t()> m_generateNumber;

    static constexpr auto DEFAULT_NUMER_OF_ROUNDS = 100;
    static constexpr auto DEFAULT_SCORES_TO_WIN = 50;
};