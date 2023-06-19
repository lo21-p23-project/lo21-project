/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

#include "Border.h"

namespace Model::Shotten::Board::Entities {
  Border::Border() {
    this->combo = nullptr;
  }

  void Border::initializeCombo(std::shared_ptr<Player::Player> engagedBy, std::shared_ptr<Card> card) {
    this->combo = std::make_shared<Combo>(engagedBy, card);
  }
}
