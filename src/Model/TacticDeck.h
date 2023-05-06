/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_TACTICDECK_H
#define LO21_PROJECT_TACTICDECK_H

#include <vector>

#include "Deck.h"
#include "TacticCard.h"

class TacticDeck : public Deck {
private:
  std::vector<TacticCard> cards;
};

#endif//LO21_PROJECT_TACTICDECK_H
