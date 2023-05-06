/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

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

#endif//LO21_PROJECT_PLAYER_H
