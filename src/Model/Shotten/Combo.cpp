//
// Created by Pierre Roussel on 4/17/23.
//

#include "Combo.h"

namespace Model::Shotten {

/**
 * Constructor of the Combo class
 * @param engagedBy
 * @param card
 */
Combo::Combo(Player::Player *engagedBy, std::shared_ptr<Card> card) {
  this->engagedBy_ = engagedBy;

  this->cards_[this->cardsNumber_] = card;

  this->cardsNumber_++;
}

/**
 * Adds a new card inside the Combo
 * @param card
 */
void Combo::addCard(std::shared_ptr<Card> card) {
  if (this->cardsNumber_ >= this->cards_.size())
    throw std::exception("Can't add any new element to the Combo: Combo is full");

  for (size_t i = 0; i < this->cardsNumber_; ++i) {
    if (this->cards_[i] == nullptr) { /* we just found a free space to put our reference to a Card */
      this->cards_[i] = card;
      return;
    }
  }

  this->cardsNumber_++;
}

/**
 * Delete a reference to a card in the cards array of the current combo
 * @param card
 */
void Combo::deleteCard(std::shared_ptr<Card> card) {
  for (size_t i = 0; i < this->cardsNumber_; i++) {
    if (this->cards_[i] == card) {
      this->cards_[i] = nullptr;
      return;
    }
  }

  this->cardsNumber_--;
}

}// namespace Model::Shotten
