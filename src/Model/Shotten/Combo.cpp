//
// Created by Pierre Roussel on 4/17/23.
//

#include "Combo.h"

namespace Model::Shotten {

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

      int value = card->getValue();
      this->sum_ += value;

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
      /* we don't forget to remove the value of the card from the sum */
      int value = this->cards_[i]->getValue();
      this->sum_ -= value;

      this->cards_[i] = nullptr;
      return;
    }
  }

  this->cardsNumber_--;
}

/**
 * Returns whether or not the combo is a color run
 * @return bool
 */
bool Combo::isColorRun() {
  std::sort(cards_.begin(), cards_.end(),
            [](const std::shared_ptr<Card> &a, const std::shared_ptr<Card> &b) { return a->getValue() < b->getValue(); });

  for (size_t i = 1; i < cardsNumber_; i++) {
    if (cards_[i]->getColor() != cards_[0]->getColor() || cards_[i]->getValue() != cards_[i - 1]->getValue() + 1) {
      return false;
    }
  }

  return true;
}

/**
 * Returns whether or not the actual combo is a three of a kind
 * @return bool
 */
bool Combo::isThreeOfAKind() {
  /* Three of a kind means 3 cards of the same value */
  std::array<int, MAX_CARD_VALUE + 1> frequencies{};

  for (size_t i = 0; i < cardsNumber_; i++)
    if (++frequencies[cards_[i]->getValue()] == 3)
      return true;

  return false;
}

/**
 * Returns whether or not this combo is a color combo
 * @return bool
 */
bool Combo::isColor() {
  for (size_t i = 1; i < cardsNumber_; i++)
    if (cards_[i]->getColor() != cards_[0]->getColor())
      return false;

  return true;
}

/**
 * Returns whether or not the current combo is a run
 * @return bool
 */
bool Combo::isRun() {
  std::sort(cards_.begin(), cards_.end(),
            [](const std::shared_ptr<Card> &a, const std::shared_ptr<Card> &b) { return a->getValue() < b->getValue(); });

  for (size_t i = 1; i < cardsNumber_; i++) {
    if (cards_[i]->getValue() != cards_[i - 1]->getValue() + 1) {
      return false;
    }
  }

  return true;
}

/**
 * Gets the current combination of the combo
 * @return Combination
 */
Combination Combo::getCombination() {
  if (cardsNumber_ < 3) {
    return Combination::NONE;
  }

  if (false) {// TODO: Implement a way to handle Tactic combos with a special method that handles that
    return Combination::NONE;
  }

  // TODO: Test these methods with actual real values (for the moment, this is UNTESTED)

  /* If no tactical combination we can proceed with regular checks */
  if (isColorRun())
    return Combination::COLOR_RUN;

  if (isThreeOfAKind())
    return Combination::THREE_OF_A_KIND;

  if (isColor())
    return Combination::COLOR;

  if (isRun())
    return Combination::RUN;

  return Combination::NONE;
}
}// namespace Model::Shotten
