//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_NORMALDECK_H
#define LO21_PROJECT_NORMALDECK_H

#include <vector>

#include "../../Cards/CardTypes/NormalCard.h"
#include "../Deck.h"

namespace Model::Shotten {
class NormalDeck : public Deck {
private:
  std::vector<NormalCard> cards;
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_NORMALDECK_H
