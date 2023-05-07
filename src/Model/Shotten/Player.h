//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_PLAYER_H
#define LO21_PROJECT_PLAYER_H

#include <string>

#include "../../Constants/Constants.h"
#include "../EventManager.h"
#include "../ISubscriber.h"
#include "Hand.h"

namespace Model::Shotten {
class Player : ISubscriber<Player *> {
private:
  std::string username;
  std::string lastTripDestination;
  Hand hand;
  unsigned int claimedBorders;

public:
  void trigger(Player *);

  EventManager<std::pair<Player *, Phase>> turnEvents;
};
}// namespace Model::Shotten

#endif//LO21_PROJECT_PLAYER_H
