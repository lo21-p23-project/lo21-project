/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/10/2023
 * @copyright Copyright 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H
#define LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H

#include "../Model/Shotten/Game.h"
#include "../Model/Shotten/GameOptions.h"

#include <iostream>

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
   * @return GameOptions*
   */
  static GameOptions *createGameOption(GameVersion version, ModeOptions modeOptions, bool isExpert, bool aiMode, unsigned int maxRounds) {
    GameOptions *gameOptions = new GameOptions();

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
   * @return Player*
   */
  static Player::Player *createPlayer(std::string username, std::string lastTripDestination, std::chrono::year_month_day birthday) {
    Player::Player *ply = new Player::Player(username, lastTripDestination, birthday);

    return ply;
  }

  /**
   * @brief Create a new Game based on all the given parameters
   * @param gameOptions
   * @param players
   * @param board
   * @return Game*
   */
  static Game *createGame(GameOptions *gameOptions, std::pair<Player::Player *, Player::Player *> players, Board *board) {
    Game *game = Game::getInstance(gameOptions, players, board);

    return game;
  }
};
}// namespace Controller
#endif//LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H
