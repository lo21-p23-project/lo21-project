/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

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
  std::shared_ptr<Player::Player> engagedBy_;
  std::array<std::shared_ptr<Card>, COMBO_MAX_SIZE> cards_;
  Combination combination_;
  unsigned int sum_;

  size_t cardsNumber_ = 0;

public:
  Combo(std::shared_ptr<Player::Player>, std::shared_ptr<Card>);

  void addCard(std::shared_ptr<Card> card);
  void deleteCard(std::shared_ptr<Card> card);

  Combination getCombination();
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_COMBO_H
