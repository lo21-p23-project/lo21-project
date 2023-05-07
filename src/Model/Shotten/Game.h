//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_GAME_H
#define LO21_PROJECT_GAME_H

#include "Board.h"
#include "GameOptions.h"
#include "Player.h"
#include "Round.h"
#include <vector>

#include "../EventManager.h"
#include "../ISubscriber.h"

namespace Model::Shotten {
/**
 * Game class: Handles the logic and behaviour of the game
 */
class Game {
private:
  GameOptions *gameOptions_;
  std::pair<Player, Player> players_;
  Round *currentRound_;
  Board *board_;

  Game(GameOptions *, std::pair<Player, Player>, Round *, Board *);

protected:
  static Game *game_;

public:
  Game(Game &) = delete;
  void operator=(const Game &) = delete;
  ~Game();

  Game *getInstance(GameOptions *options, std::pair<Player, Player> players) {
    if (game_ == nullptr) {
      auto round = new Round();
      auto board = new Board();

      game_ = new Game(options, players, round, board);
    }

    return game_;
  }

  Game *getInstance() {
    if (game_ == nullptr)
      throw std::exception("No game actually exists.");

    return game_;
  }
};
}// namespace Shotten
#endif//LO21_PROJECT_GAME_H
