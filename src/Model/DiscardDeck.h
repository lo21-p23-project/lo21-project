//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_DISCARDDECK_H
#define LO21_PROJECT_DISCARDDECK_H

#include <vector>

#include "Deck.h"
#include "Card.h"

class DiscardDeck : public Deck {
private:
    std::vector<Card> cards;
};


#endif //LO21_PROJECT_DISCARDDECK_H
