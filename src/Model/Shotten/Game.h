/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

#ifndef LO21_PROJECT_GAME_H
#define LO21_PROJECT_GAME_H

#include "Board/Board.h"
#include "GameOptions.h"
#include "Player/Player.h"
#include "Round.h"
#include <utility>
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
  std::shared_ptr<GameOptions> gameOptions_;
  std::pair<std::shared_ptr<Player::Player>, std::shared_ptr<Player::Player>> players_;
  std::shared_ptr<Round> currentRound_;

  Game(std::shared_ptr<GameOptions> gameOptions, std::pair<std::shared_ptr<Player::Player>, std::shared_ptr<Player::Player>> players)
      : gameOptions_(std::move(gameOptions)), players_(std::move(players)){};

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
  static Game *getInstance(std::shared_ptr<GameOptions> options, std::pair<std::shared_ptr<Player::Player>, std::shared_ptr<Player::Player>> players) {
    if (game_ == nullptr)
      game_ = new Game(std::move(options), std::move(players));

    return game_;
  }

  static Game *getInstance() {
    if (game_ == nullptr) {
      // throw std::exception("No game actually exists.");
      return nullptr;
    }

    return game_;
  }

  /**
   * @brief Getter for the GameOption object
   * @return std::shared_ptr<GameOptions>
   */
  auto getGameOption() const {
    return this->gameOptions_;
  }

  /**
   * @brief Getter for the current round
   * @return std::shared_ptr<Round>
   */
  auto getRound() const {
    return this->currentRound_;
  }

  /**
   * @brief Creates a new round for the game
   */
  void newRound() {
    this->currentRound_ = std::make_shared<Round>();
  }

  /**
   * @brief Getter for the players pair
   * @return std::pair<Player, Player>
   */
  auto getPlayers() {
    return this->players_;
  }
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_GAME_H
