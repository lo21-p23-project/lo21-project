//
// Created by Pierre Roussel on 4/17/23.
//

#include "Board.h"
#include <iostream>

using namespace Model::Shotten::Board::Entities;

namespace Model::Shotten::Board {

Board::Board(GameVersion gameVersion) {
  this->normalDeck = NormalDeck::getInstance();
  // TODO : this->discardDeck = DiscardDeck::getInstance();
}

/**
 * @brief Returns a border by its Id
 * @return
 */
std::shared_ptr<Border> Board::getBorderById(int id) {
  for (auto border : this->borders)
    if (border->getId() == id)
      return border;

  return nullptr;
}

/**
 * @brief Returns whether or not the player can play the card at the given position inside the border
 * @param card
 * @return
 */
bool Board::canPlayCard(std::shared_ptr<Model::Shotten::Player::Player> ply, Model::Shotten::Card card, int borderId) {
  auto border = getBorderById(borderId);
  if (border == nullptr) {
    std::cerr << "An error occured while trying to get the right border to put the card on" << std::endl;
    return false;
  }

  /* Check if there is an existing combo */
  if (auto combo = border->getCombo()) {
    /* Check if the combo was initiated by the same player */
    if (combo->getEngagedBy() == ply)
      /* Check if the combo is not full yet */
      if (combo->getCardsNumber() < 4)
        /* Card can be played */
        return true;
      else
        std::cerr << "The combo is full. Can't play card here." << std::endl;
    else
      std::cerr << "This combo was initiated by the other player. Can't play card here." << std::endl;
  } else {
    /* If there's no existing combo, the card can be played */
    return true;
  }

  return false;
}

}// namespace Model::Shotten::Board
