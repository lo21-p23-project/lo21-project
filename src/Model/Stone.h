//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_STONE_H
#define LO21_PROJECT_STONE_H

#include <string>

#include "CombatMode.h"
#include "Border.h"

class Stone : public Border {
private:
  CombatMode combatMode;
  std::string claimedBy;
};


#endif //LO21_PROJECT_STONE_H
