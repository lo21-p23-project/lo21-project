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

namespace Model::Shotten {
class NormalDeck : public Deck {
public:
  ~NormalDeck();

  static NormalDeck *getInstance(GameVersion gameVersion) {
    if (normalDeck_ == nullptr)
      normalDeck_ = new NormalDeck(gameVersion);

    return normalDeck_;
  }

  static NormalDeck *getInstance() {
    if (normalDeck_ == nullptr)
      // throw std::runtime_error("NormalDeck not initialized");
      return nullptr;

    return normalDeck_;
  }

  static void destroyInstance() {
    delete normalDeck_;
    normalDeck_ = nullptr;
  }

  [[nodiscard]] unsigned int getRemainingCards() const { return cards_.size(); }

  NormalCard *draw();

private:
  static NormalDeck *normalDeck_;
  std::vector<NormalCard *> cards_;

  explicit NormalDeck(GameVersion gameVersion);
  void shuffle();
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_NORMALDECK_H