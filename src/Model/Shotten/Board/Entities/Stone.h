//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_STONE_H
#define LO21_PROJECT_STONE_H

#include <string>

#include "../../Cards/CardTypes/Tactic/CombatMode.h"
#include "Border.h"

namespace Model::Shotten::Entities {
class Stone : public Border {
private:
  CombatMode combatMode;
  std::string claimedBy;
};
}// namespace Model::Shotten::Entities
#endif//LO21_PROJECT_STONE_H
