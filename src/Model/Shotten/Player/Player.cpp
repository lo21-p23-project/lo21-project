/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

#include "Player.h"

namespace Model::Shotten::Player {
/**
 * Player constructor
 * @param name username of the player
 * @param lastTripDestination used to determine which player has traveled the nearest to Ireland
 */
Player::Player(std::string name, std::string lastTripDestination) {
  this->username_ = name;
  this->lastTripDestination_ = lastTripDestination;
  this->hand_ = std::make_shared<Hand>();
  this->claimedBorders_ = 0;
}

void Player::trigger(std::shared_ptr<Player> message) {
  if (this != message.get())
    return; /* it's not the turn of our player */


}

void Player::trigger() {
  return;
}
}// namespace Model::Shotten::Player