/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/14/2023
* @copyright Copyright 2023 All rights reserved.
*/

#ifndef LO21_PROJECT_BOARD_H
#define LO21_PROJECT_BOARD_H

#include <vector>

#include "../Deck/DeckTypes/DiscardDeck.h"
#include "../Deck/DeckTypes/NormalDeck.h"
#include "../Deck/DeckTypes/TacticDeck.h"
#include "Entities/Border.h"

using namespace Model::Shotten::Board::Entities;

namespace Model::Shotten::Board {
class Board {
private:
  std::shared_ptr<NormalDeck> normalDeck;
  std::shared_ptr<TacticDeck> tacticDeck;
  std::shared_ptr<DiscardDeck> discardDeck;
  std::vector<std::shared_ptr<Border>> borders;

  std::shared_ptr<Border> getBorderById(int id);
  bool canPlayCard(std::shared_ptr<Model::Shotten::Player::Player>, Model::Shotten::Card, int);
public:
  Board(GameVersion gameVersion);
};
}// namespace Model::Shotten::Board

#endif
