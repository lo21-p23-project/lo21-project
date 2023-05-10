//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_DISCARDDECK_H
#define LO21_PROJECT_DISCARDDECK_H

#include <vector>

#include "../../Cards/Card.h"
#include "../Deck.h"

namespace Model::Shotten {
class DiscardDeck : public Deck {
private:
  std::vector<Card> cards;
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_DISCARDDECK_H
