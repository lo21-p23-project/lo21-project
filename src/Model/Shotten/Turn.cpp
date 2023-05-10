//
// Created by Pierre Roussel on 4/17/23.
//

#include "Turn.h"

using namespace Model::Shotten;

Turn::Turn(Player::Player *one, Player::Player *two) {
}

void Turn::trigger() {
}

void Turn::trigger(std::pair<Player::Player *, Phase> message) {
  Player::Player *ply = message.first;
  Phase phase = message.second;// TODO: Rework the Phase enum so that it contains what the player choosed to play
  if (ply != voiceTo_)         // TODO: Handle the problem with the UI
  {
    // throw std::exception("It's not the turn to the player yet");
    return;
  }

  // TODO: Finish the logic of handling player plays
}
