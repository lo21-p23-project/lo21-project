//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_BOARD_H
#define LO21_PROJECT_BOARD_H

#include <vector>

#include "Border.h"
#include "DiscardDeck.h"
#include "NormalDeck.h"
#include "TacticDeck.h"

namespace Model::Shotten {
class Board {
private:
  NormalDeck normalDeck;
  TacticDeck tacticDeck;
  DiscardDeck discardDeck;
  std::vector<Border> borders;
};
}// namespace Model::Shotten

#endif//LO21_PROJECT_BOARD_H
