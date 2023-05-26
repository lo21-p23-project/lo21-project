/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/10/2023
 * @copyright Copyright 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H
#define LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H

#include <utility>

#include "../Model/Shotten/Game.h"
#include "../Model/Shotten/GameOptions.h"

using namespace Model::Shotten;

namespace Controller {
class GameCreationController {
public:
  /**
   * @brief Creates a new GameOptions object with given params
   * @param version
   * @param modeOptions
   * @param isExpert
   * @param aiMode
   * @param maxRounds
   * @return std::shared_ptr<GameOptions>
   */
  static auto createGameOption(GameVersion version, ModeOptions modeOptions, bool isExpert, bool aiMode, unsigned int maxRounds) {
    auto gameOptions = std::make_shared<GameOptions>();

    gameOptions->version = version;
    gameOptions->modeOptions = modeOptions;
    gameOptions->isExpert = isExpert;
    gameOptions->aiMode = aiMode;
    gameOptions->maxRounds = maxRounds;

    return gameOptions;
  }

  /**
   * @brief Creates a new Player object with the given params
   * @param username
   * @param lastTripDestination
   * @param birthday
   * @return std::shared_ptr<Player::Player>
   */
  static auto createPlayer(const std::string &username, const std::string &lastTripDestination, date::year_month_day birthday) {
    auto ply = std::make_shared<Player::Player>(username, lastTripDestination, birthday);
    return ply;
  }

  /**
   * @brief Create a new Game based on all the given parameters
   * @param gameOptions
   * @param players
   * @param board
   * @return Game*
   */
  static Game *createGame(std::shared_ptr<GameOptions> gameOptions, std::pair<std::shared_ptr<Player::Player>, std::shared_ptr<Player::Player>> players, std::shared_ptr<Board::Board> board) {// TODO: Fix namespace Board
    Game *game = Game::getInstance(std::move(gameOptions), std::move(players), std::move(board));

    return game;
  }
};
}// namespace Controller
#endif//LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H
