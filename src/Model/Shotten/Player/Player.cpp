//
// Created by Pierre Roussel on 4/17/23.
//

#include "Player.h"

using namespace Model::Shotten::Player;

/**
 * Player constructor
 * @param name username of the player
 * @param lastTripDestination used to determine which player has traveled the nearest to Ireland
 */
Player::Player(std::string name, std::string lastTripDestination, std::chrono::year_month_day birthday) {
  this->username_ = name;
  this->lastTripDestination_ = lastTripDestination;
  this->birthDay_ = birthday;
  this->hand_ = new Hand();
  this->claimedBorders_ = 0;
}

void Player::trigger(Player * message) {
  if (this != message)
    return; /* it's not the turn of our player */

  // TODO: Trigger event to the UI to display the actual playable actions
}

void Player::trigger() {
  return;
}
