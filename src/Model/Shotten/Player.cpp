//
// Created by Pierre Roussel on 4/17/23.
//

#include "Player.h"

using namespace Model::Shotten;

void Player::trigger(Player * message) {
  if (this != message)
    return; /* it's not the turn of our player */

  // TODO: Trigger event to the UI to display the actual playable actions

}
