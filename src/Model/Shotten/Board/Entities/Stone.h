//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_STONE_H
#define LO21_PROJECT_STONE_H

#include <string>

#include "../../Cards/CardTypes/Tactic/CombatMode.h"
#include "Border.h"

namespace Model::Shotten::Board::Entities {
class Stone : Border {
private:
  CombatMode combatMode_;
  std::shared_ptr<Player::Player> claimedBy_;

public:
  void setClaimedBy(std::shared_ptr<Player::Player>);
  std::shared_ptr<Player::Player> getClaimedBy();
  void unclaim();
  CombatMode getCombatMode() const { return combatMode_; }
  void setCombatMode(CombatMode mode) { this->combatMode_ = mode; }
  bool isClaimable();
  std::shared_ptr<Player::Player> getWinner();
};
}// namespace Model::Shotten::Board::Entities
#endif//LO21_PROJECT_STONE_H
