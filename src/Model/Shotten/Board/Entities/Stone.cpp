//
// Created by Pierre Roussel on 4/17/23.
//

#include "Stone.h"

#include <utility>

namespace Model::Shotten::Board::Entities {

/**
 * Unclaims the border of the
 */
void Stone::unclaim() {
  this->claimedBy_ = nullptr;
}

/**
 * Sets the stone to be claimed by the given player
 * @param ply
 */
void Stone::setClaimedBy(std::shared_ptr<Player::Player> ply) {
  this->claimedBy_ = std::move(ply);
}

/**
 * Returns the player that claimed the stone
 * @return std::shared_ptr Player::Player
 */
std::shared_ptr<Player::Player> Stone::getClaimedBy() {
  return this->claimedBy_;
}

/**
 * Returns whether or not the current Stone is claimable by a player
 * this is based only on the cards that have been played on the stone
 * @return bool
 */
bool Stone::isClaimable() {
  for (const auto& pair : cards) {
    auto ply = pair.first;
    auto combo = pair.second;

    if (combo.getCardsCount() < 3) /* not all the players played all the cards for the stone */
      return false;

    // TODO: Make a check for the CombatMode requirements
  }

  return true;
}

/**
 * Returns the player that can claim the stone (the one that won the battle at the border)
 * @return std::shared_ptr<Player::Player>
 */
std::shared_ptr<Player::Player> Stone::getWinner() {
  std::pair<std::shared_ptr<Player::Player>, Combination> winner;
  for (const auto& pair : cards) {
    auto ply = pair.first;
    auto combo = pair.second;

    // TODO: Make a check for the CombatMode requirements
    if (combo.getCombination() < winner.second) { /* combination is greater than the already saved combination */
      winner.first = ply;
      winner.second = combo.getCombination();
    } else if (combo.getCombination() == winner.second) { /* we have the same combination power */
      auto lastSum = cards.at(winner.first).getSum();

      if (combo.getSum() > lastSum) {
        winner.first = ply;
        winner.second = combo.getCombination();
      }

      if (combo.getSum() == lastSum) {
        // TODO: Implement the check for the last player to have played the 3rd class
      }
    }
  }

  return winner.first;
}

}// namespace Model::Shotten::Board::Entities
