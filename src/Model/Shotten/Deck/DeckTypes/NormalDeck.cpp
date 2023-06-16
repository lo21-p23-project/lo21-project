//
// Created by Pierre Roussel on 4/17/23.
//

#include "NormalDeck.h"

namespace Model::Shotten {

NormalDeck *NormalDeck::normalDeck_ = nullptr;

NormalDeck::NormalDeck(GameVersion gameVersion) {
  const unsigned int numberOfCards = gameVersion == GameVersion::VERSION1 ? 54 : 60;
  const unsigned int numberOfColors = gameVersion == GameVersion::VERSION1 ? 6 : 5;
  const unsigned int startingValue = gameVersion == GameVersion::VERSION1 ? 1 : 0;

  for (unsigned int i = 0; i < numberOfCards; ++i) {
    unsigned int value = i / numberOfColors + startingValue;
    Color color = Color(i % numberOfColors);

    cards_.push_back(new NormalCard(value, color));
  }

  shuffle();
}

NormalDeck::~NormalDeck() {
  for (NormalCard *card : cards_) {
    delete card;
  }
}

NormalCard *NormalDeck::draw() {
  NormalCard *card = cards_.back();
  cards_.pop_back();
  return card;
}

void NormalDeck::shuffle() {
  auto rng = std::default_random_engine {};
  std::shuffle(cards_.begin(), cards_.end(), rng);
}
}// namespace Model::Shotten