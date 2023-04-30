//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_PLAYER_H
#define LO21_PROJECT_PLAYER_H

#include <string>

#include "Hand.h"

class Player {
private:
  std::string username;
  std::string lastTripDestination;
  Hand hand;
  unsigned int claimedBorders;
public:
};


#endif //LO21_PROJECT_PLAYER_H
