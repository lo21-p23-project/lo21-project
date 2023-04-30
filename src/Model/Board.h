//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_BOARD_H
#define LO21_PROJECT_BOARD_H

#include <vector>

#include "NormalDeck.h"
#include "TacticDeck.h"
#include "DiscardDeck.h"
#include "Border.h"

class Board {
private:
  NormalDeck normalDeck;
  TacticDeck tacticDeck;
  DiscardDeck discardDeck;
  std::vector<Border> borders;
};


#endif //LO21_PROJECT_BOARD_H
