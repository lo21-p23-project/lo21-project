/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_STONE_H
#define LO21_PROJECT_STONE_H

#include <string>

#include "Border.h"
#include "CombatMode.h"

class Stone : public Border {
private:
  CombatMode combatMode;
  std::string claimedBy;
};

#endif//LO21_PROJECT_STONE_H
