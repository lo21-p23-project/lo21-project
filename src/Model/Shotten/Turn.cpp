//
// Created by Pierre Roussel on 4/17/23.
//

#include "Turn.h"

using namespace Model::Shotten;

Turn::Turn(std::shared_ptr<Player::Player> one, std::shared_ptr<Player::Player> two) {
}

void Turn::trigger() {
}

void Turn::trigger(std::pair<std::shared_ptr<Player::Player>, Phase> message) {
  std::shared_ptr<Player::Player> ply = message.first;
  Phase phase = message.second;// TODO: Rework the Phase enum so that it contains what the player choosed to play
  if (ply != voiceTo_)         // TODO: Handle the problem with the UI
    return;

  // TODO: Finish the logic of handling player plays
}
