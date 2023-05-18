//
// Created by Pierre Roussel on 4/17/23.
//

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
  NormalDeck normalDeck;
  TacticDeck tacticDeck;
  DiscardDeck discardDeck;
  std::vector<Border> borders;
};
}// namespace Model::Shotten::Board

#endif
