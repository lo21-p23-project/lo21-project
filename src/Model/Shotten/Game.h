//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_GAME_H
#define LO21_PROJECT_GAME_H

#include "Board/Board.h"
#include "GameOptions.h"
#include "Player/Player.h"
#include "Round.h"
#include <vector>

#include "../EventManager.h"
#include "../ISubscriber.h"

using namespace Model::Shotten;

namespace Model::Shotten {

/**
 * Game class: Handles the logic and behaviour of the game
 */
class Game {
private:
  GameOptions *gameOptions_;
  std::pair<Player::Player *, Player::Player *> players_;
  Round *currentRound_;
  Board *board_;

  Game(GameOptions *, std::pair<Player::Player *, Player::Player *>, Board *);

protected:
  static Game *game_;

public:
  Game(Game &) = delete;
  void operator=(const Game &) = delete;
  ~Game();

  /**
   * @brief Returns an instance of a Game. Given parameters are using if and only if no game has been already created
   * @param options
   * @param players
   * @return Game
   */
  static Game *getInstance(GameOptions *options, std::pair<Player::Player *, Player::Player *> players, Board *board) {
    if (game_ == nullptr)
      game_ = new Game(options, players, board);

    return game_;
  }

  static Game *getInstance() {
    if (game_ == nullptr)
      throw std::exception("No game actually exists.");

    return game_;
  }

  /**
   * @brief Getter for the GameOption object
   * @return GameOptions*
   */
  GameOptions *getGameOption() const {
    return this->gameOptions_;
  }

  /**
   * @brief Getter for the currentRound object
   * @return Round*
   */
  Round *getCurrentBoard() const {
    return this->currentRound_;
  }

  /**
   * @brief Getter for the Board object
   * @return Board*
   */
  Board *getBoard() const {
    return this->board_;
  }
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_GAME_H
