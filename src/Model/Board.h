/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_BOARD_H
#define LO21_PROJECT_BOARD_H

#include <vector>

#include "Border.h"
#include "DiscardDeck.h"
#include "NormalDeck.h"
#include "TacticDeck.h"

class Board {
private:
  NormalDeck normalDeck;
  TacticDeck tacticDeck;
  DiscardDeck discardDeck;
  std::vector<Border> borders;
};

#endif//LO21_PROJECT_BOARD_H
