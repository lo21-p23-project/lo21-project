//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_ROUND_H
#define LO21_PROJECT_ROUND_H

#include <string>

#include "Turn.h"

namespace Model::Shotten {
class Round {
private:
  unsigned int id;
  std::string winner;
  std::shared_ptr<Turn> turn;

public:
  Round();

  /*
   * @brief Creates a new Turn for this round
   * @param std::pair<std::shared_ptr<Player::Player>, std::shared_ptr<Player::Player>> players
   * @return void
   */
  void newTurn(std::pair<std::shared_ptr<Player::Player>, std::shared_ptr<Player::Player>> players) {
     turn = std::make_shared<Turn>(players.first, players.second);
  }

  /**
   * @brief Returns the current Turn inside the round
   * @return std::shared_ptr<Turn>
   */
  auto getTurn() {
     return this->turn;
  }


};
}// namespace Model::Shotten
#endif//LO21_PROJECT_ROUND_H
