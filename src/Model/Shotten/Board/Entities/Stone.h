//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_STONE_H
#define LO21_PROJECT_STONE_H

#include <string>

#include "../../Cards/CardTypes/Tactic/CombatMode.h"
#include "Border.h"

namespace Model::Shotten::Board::Entities {
class Stone : public Border {
private:
  CombatMode combatMode_;
  std::shared_ptr<Player::Player> claimedBy_;
public:
  void setClaimedBy(std::shared_ptr<Player::Player>);
  void unclaim();
  CombatMode getCombatMode() const { return combatMode_; }
  void setCombatMode(CombatMode mode) { this->combatMode_ = mode; }

};
}// namespace Model::Shotten::Entities
#endif//LO21_PROJECT_STONE_H
