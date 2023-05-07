//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_STONE_H
#define LO21_PROJECT_STONE_H

#include <string>

#include "Border.h"
#include "CombatMode.h"

namespace Model::Shotten {
class Stone : public Border {
private:
  CombatMode combatMode;
  std::string claimedBy;
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_STONE_H
