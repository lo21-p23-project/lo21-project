//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_BORDER_H
#define LO21_PROJECT_BORDER_H

#include "../../../../Constants/Constants.h"
#include "../../Combo.h"

namespace Model::Shotten::Board::Entities {
class Border {
protected:
  unsigned int id;
  Rules rules;

  std::unordered_map<std::shared_ptr<Player::Player>, Combo> cards;
public:
  void updateRules(Rules);
  Rules getRules();

  /**
   * Adds a new card to the given player's side of the boarder
   * @paramc ply
   * @param card
   */
  void addCard(std::shared_ptr<Player::Player> ply, std::shared_ptr<Card> card) {
    cards[ply].addCard(card);
  }

  /**
   * Removes a card from the border placement
   * @param ply
   * @param card
   */
  void removeCard(std::shared_ptr<Player::Player> ply, std::shared_ptr<Card> card) {
    cards.at(ply).deleteCard(card);
  }

  /**
   * Gets the cards that a player put into the border
   * @param ply
   * @return std::vector<std::shared_ptr<Card>>
   */
  auto getPlayerCards(std::shared_ptr<Player::Player> ply) {
    return cards.at(ply).getCards();
  }

  /**
   * Returns the combination of the given player for this border
   * @param ply
   * @return Combination
   */
  auto getPlayerCombination(std::shared_ptr<Player::Player> ply) {
    return cards.at(ply).getCombination();
  }
};
}// namespace Model::Shotten::Board::Entities
#endif//LO21_PROJECT_BORDER_H
