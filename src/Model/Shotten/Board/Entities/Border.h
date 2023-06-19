/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

#ifndef LO21_PROJECT_BORDER_H
#define LO21_PROJECT_BORDER_H

#include "../../../../Constants/Constants.h"
#include "../../Combo.h"

namespace Model::Shotten::Board::Entities {
class Border {
protected:
  unsigned int id;
  std::shared_ptr<Combo> combo;
  Rules rules;
public:
  Border();
  auto getId() { return this->id; }
  auto getCombo() { return this->combo; }
  void initializeCombo(std::shared_ptr<Player::Player> engagedBy, std::shared_ptr<Card> card);
};
}// namespace Model::Shotten::Board::Entities
#endif//LO21_PROJECT_BORDER_H
