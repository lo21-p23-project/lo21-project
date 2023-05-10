//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_TURNS_H
#define LO21_PROJECT_TURNS_H

#include "../../Constants/Constants.h"
#include "../EventManager.h"
#include "Player/Player.h"
#include <string>

namespace Model::Shotten {
class Turn : ISubscriber<std::pair<Player *, Phase>> {
private:
  unsigned int id_;
  Player *voiceTo_;
  Phase phase_;

public:
  Turn(Player *, Player *);
  void setPhase(Phase phase) { phase_ = phase; }
  Phase getPhase() const { return phase_; }

  void trigger(std::pair<Player *, Phase>) override;

  EventManager<Player *> playerEvents;
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_TURNS_H
