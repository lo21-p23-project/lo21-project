/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_NORMALDECK_H
#define LO21_PROJECT_NORMALDECK_H

#include <vector>

#include "Deck.h"
#include "NormalCard.h"

class NormalDeck : public Deck {
private:
  std::vector<NormalCard> cards;
};

#endif//LO21_PROJECT_NORMALDECK_H
