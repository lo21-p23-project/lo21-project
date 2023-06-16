//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_TURNS_H
#define LO21_PROJECT_TURNS_H

#include "../../Constants/Constants.h"
#include "../EventManager.h"
#include "Player/Player.h"
#include "Game.h"

#include <random>
#include <string>

namespace Model::Shotten {
class Turn : ISubscriber<std::pair<Player::Player *, Phase>> {
private:
  unsigned int id_;
  Player::Player *voiceTo_;
  Phase phase_;

public:
  Turn(unsigned int id, Player::Player *voiceTo, Phase phase)
      : id_(id), voiceTo_(voiceTo), phase_(phase) {
    if (voiceTo_ == nullptr) {
      std::random_device rd;
      std::mt19937 gen(rd());  // Initialize the random number generator
      std::uniform_int_distribution<int> dist(0, 1);  // Define the range [0, 1]

      int randomInteger = dist(gen);  // Generate a random integer
      voiceTo_ = Game::getInstance()->getPlayers()[randomInteger];
    }

  }
  unsigned int getId() const { return id_; }
  Player::Player *getVoiceTo() const { return voiceTo_; }
  void setPhase(Phase phase) { phase_ = phase; }
  Phase getPhase() const { return phase_; }

  void trigger(std::pair<Player::Player *, Phase>) override;
  void trigger() override;

  EventManager<Player::Player *> playerEvents;
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_TURNS_H
