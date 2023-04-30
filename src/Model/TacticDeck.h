//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_TACTICDECK_H
#define LO21_PROJECT_TACTICDECK_H

#include <vector>

#include "Deck.h"
#include "TacticCard.h"

class TacticDeck : public Deck {
private:
  std::vector<TacticCard> cards;
};


#endif //LO21_PROJECT_TACTICDECK_H
