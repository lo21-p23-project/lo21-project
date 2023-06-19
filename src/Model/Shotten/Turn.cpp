//
// Created by Pierre Roussel on 4/17/23.
//

#include "Turn.h"
#include <iostream>

using namespace Model::Shotten;

Turn::Turn(std::shared_ptr<Player::Player> one, std::shared_ptr<Player::Player> two) {
  /* We need to initialize fist the first player that will play the turn */
  int starting_ply = rand() % 2;
  if (starting_ply == 0)
    this->voiceTo_ = one;
  else
    this->voiceTo_ = two;

  this->players.first = one;
  this->players.second = two;

  // this->playerEvents.subscribe("TurnEvent", one);
  // this->playerEvents.subscribe("TurnEvent", two);
}

/** Nothing to do when trigger is called without any message */
void Turn::trigger() {
  return;
}

void Turn::trigger(std::pair<std::shared_ptr<Player::Player>, Phase> message) {
  std::shared_ptr<Player::Player> ply = message.first;
  Phase phase = message.second;// TODO: Rework the Phase enum so that it contains what the player choosed to play
  if (ply != voiceTo_)         // TODO: Handle the problem with the UI
    return;

  if (phase == Phase::PASS) {
    std::cout << "You decided to pass your turn." << std::endl;

    this->voiceTo_ = this->players.first == ply ? this->players.second : this->players.first ;
  }
}
