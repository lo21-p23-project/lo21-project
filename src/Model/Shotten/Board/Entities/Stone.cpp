//
// Created by Pierre Roussel on 4/17/23.
//

#include "Stone.h"

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
  this->claimedBy_ = ply;
}

}
