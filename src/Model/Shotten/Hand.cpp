/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

#include "Hand.h"

namespace Model::Shotten {

/**
 * Returns the number of cards inside the current hand
 * @return int
 */
int Hand::cardsCount() {
  return this->cards.size();
}

/**
 * Adds a new card to the current hand
 * @param card
 */
void Hand::addCard(std::shared_ptr<Card> card) {
  this->cards.push_back(card);
}

/**
 * Remove a card from the hand
 * @param card
 */
void Hand::removeCard(std::shared_ptr<Card> toDelete) {
  for (auto it = cards.begin(); it != cards.end(); ++it) {
    if (*it == toDelete) {
      cards.erase(it);
      break;
    }
  }
}

}// namespace Model::Shotten
