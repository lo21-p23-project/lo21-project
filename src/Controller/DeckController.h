//
// Created by Pierre Roussel on 6/16/23.
//

#ifndef LO21_PROJECT_DECKCONTROLLER_H
#define LO21_PROJECT_DECKCONTROLLER_H

#include "../Constants/Constants.h"
#include "../Model/Shotten/Deck/DeckTypes/NormalDeck.h"
#include "../Model/Shotten/Deck/DeckTypes/TacticDeck.h"

using namespace Model::Shotten;

namespace Controller {

class DeckController {
public:
  static void createDeck(GameVersion gameVersion = GameVersion::VERSION1, DeckType deckType = DeckType::NORMAL) {
    switch (deckType) {
    case DeckType::NORMAL:
      NormalDeck::getInstance(gameVersion);
      break;
    case DeckType::TACTIC:
      break;
    default:
      break;
    }
  }

  static unsigned int getRemainingCards(DeckType deckType = DeckType::NORMAL) {
    switch (deckType) {
    case DeckType::NORMAL:
      return NormalDeck::getInstance()->getRemainingCards();
    case DeckType::TACTIC:
      return 0;
    default:
      return 0;
    }
  }

  static NormalCard *drawNormalCard() {
    return NormalDeck::getInstance()->draw();
  }

  static TacticCard *drawTacticCard() {
    return nullptr;
  }
};
}// namespace Controller

#endif//LO21_PROJECT_DECKCONTROLLER_H
