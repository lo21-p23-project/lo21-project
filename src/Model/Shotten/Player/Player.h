//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_PLAYER_H
#define LO21_PROJECT_PLAYER_H

#include <chrono>
#include <string>

#include "../../../Constants/Constants.h"
#include "../../EventManager.h"
#include "../../ISubscriber.h"
#include "../Hand.h"

namespace Model::Shotten::Player {
class Player : ISubscriber<std::shared_ptr<Player>> {
private:
  std::string username_;
  std::string lastTripDestination_;
  std::chrono::year_month_day birthDay_;
  std::shared_ptr<Hand> hand_;
  unsigned int claimedBorders_;

public:
  Player(std::string, std::string, std::chrono::year_month_day);

  void trigger(std::shared_ptr<Player>) override;
  void trigger() override;

  EventManager<std::pair<std::shared_ptr<Player>, Phase>> turnEvents;
};
}// namespace Model::Shotten::Player

#endif//LO21_PROJECT_PLAYER_H
