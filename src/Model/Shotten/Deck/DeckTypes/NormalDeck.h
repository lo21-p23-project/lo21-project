//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_NORMALDECK_H
#define LO21_PROJECT_NORMALDECK_H

#include <algorithm>
#include <random>
#include <vector>

#include "../../Cards/CardTypes/NormalCard.h"
#include "../Deck.h"

using namespace std;

namespace Model::Shotten {
class NormalDeck : public Deck {
public:
  static shared_ptr<NormalDeck> getInstance(GameVersion gameVersion) {
    if (normalDeck_ == nullptr)
      normalDeck_ = shared_ptr<NormalDeck>(new NormalDeck(gameVersion));

    return normalDeck_;
  }

  static shared_ptr<NormalDeck> getInstance() {
    if (normalDeck_ == nullptr)
      // throw std::runtime_error("NormalDeck not initialized");
      return nullptr;

    return normalDeck_;
  }

  [[nodiscard]] unsigned int getRemainingCards() const { return cards_.size(); }

  shared_ptr<NormalCard> draw();

private:
  static shared_ptr<NormalDeck> normalDeck_;
  vector<shared_ptr<NormalCard>> cards_;

  explicit NormalDeck(GameVersion gameVersion);
  void shuffle();
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_NORMALDECK_H