//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_TACTICDECK_H
#define LO21_PROJECT_TACTICDECK_H

#include <vector>

#include "../../Cards/CardTypes/TacticCard.h"
#include "../Deck.h"

namespace Model::Shotten {
class TacticDeck : public Deck {
private:
  std::vector<TacticCard> cards;
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_TACTICDECK_H
