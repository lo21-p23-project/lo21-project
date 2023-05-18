/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

#ifndef LO21_PROJECT_COMBO_H
#define LO21_PROJECT_COMBO_H

#include <algorithm>
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
  std::shared_ptr<Player::Player> engagedBy_;
  std::array<std::shared_ptr<Card>, COMBO_MAX_SIZE> cards_;
  Combination combination_;
  unsigned int sum_;

  bool isColorRun();
  bool isThreeOfAKind();
  bool isColor();
  bool isRun();

  size_t cardsNumber_ = 0;

public:
  Combo() = default;

  void addCard(std::shared_ptr<Card> card);
  void deleteCard(std::shared_ptr<Card> card);

  auto getCards() { return this->cards_; }
  auto getCardsCount() { return this->cardsNumber_; }

  auto getSum() { return this->sum_; }

  Combination getCombination();
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_COMBO_H
