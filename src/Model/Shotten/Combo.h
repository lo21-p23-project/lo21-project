//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_COMBO_H
#define LO21_PROJECT_COMBO_H

#include <array>
#include <memory>
#include <string>

#include "../../Constants/Constants.h"
#include "Cards/Card.h"

#include "Player/Player.h"

#define COMBO_MAX_SIZE 4

namespace Model::Shotten {
class Combo {
private:
  Player::Player *engagedBy_;
  std::array<std::shared_ptr<Card>, COMBO_MAX_SIZE> cards_;
  Combination combination_;
  unsigned int sum_;

  size_t cardsNumber_ = 0;

public:
  Combo(Player::Player *engagedBy, std::shared_ptr<Card>);

  void addCard(std::shared_ptr<Card> card);
  void deleteCard(std::shared_ptr<Card> card);

  Combination getCombination();
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_COMBO_H
