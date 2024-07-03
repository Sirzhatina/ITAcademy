#include "Player.h"

Player::Player()
// decided to avoid id 0, let players be counted from 1
: m_playerId{++id_counter}
{}


void Player::addScores(std::int16_t scores) { m_scores += scores; }

std::int16_t Player::getScores() const { return m_scores; }
std::size_t Player::getId() const { return m_playerId; }
