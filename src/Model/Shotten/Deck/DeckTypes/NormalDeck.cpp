//
// Created by Pierre Roussel on 4/17/23.
//

#include "NormalDeck.h"

namespace Model::Shotten {

shared_ptr<NormalDeck> NormalDeck::normalDeck_ = nullptr;

NormalDeck::NormalDeck(GameVersion gameVersion) {
  const unsigned int numberOfCards = gameVersion == GameVersion::VERSION1 ? 54 : 60;
  const unsigned int numberOfColors = gameVersion == GameVersion::VERSION1 ? 6 : 5;
  const unsigned int startingValue = gameVersion == GameVersion::VERSION1 ? 1 : 0;

  for (unsigned int i = 0; i < numberOfCards; ++i) {
    unsigned int value = i / numberOfColors + startingValue;
    Color color = Color(i % numberOfColors);

    cards_.push_back(make_shared<NormalCard>(value, color));
  }

  shuffle();
}

std::shared_ptr<NormalCard> NormalDeck::draw() {
  std::shared_ptr<NormalCard> card = cards_.back();
  cards_.pop_back();
  return card;
}

void NormalDeck::shuffle() {
  auto rng = std::default_random_engine{};
  std::shuffle(cards_.begin(), cards_.end(), rng);
}
}// namespace Model::Shotten