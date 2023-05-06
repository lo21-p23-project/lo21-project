/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_DISCARDDECK_H
#define LO21_PROJECT_DISCARDDECK_H

#include <vector>

#include "Card.h"
#include "Deck.h"

class DiscardDeck : public Deck {
private:
  std::vector<Card> cards;
};

#endif//LO21_PROJECT_DISCARDDECK_H
