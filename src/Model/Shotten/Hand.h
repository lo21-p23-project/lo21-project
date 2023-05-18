/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

#ifndef LO21_PROJECT_HAND_H
#define LO21_PROJECT_HAND_H

#include "Cards/Card.h"
#include <memory>
#include <vector>

namespace Model::Shotten {
class Hand {
private:
  std::vector<std::shared_ptr<Card>> cards;

public:
  Hand() = default;

  void addCard(std::shared_ptr<Card> card);
  void removeCard(std::shared_ptr<Card> card);
  int cardsCount();
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_HAND_H
