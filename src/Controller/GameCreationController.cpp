
/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/10/2023
 * @copyright Copyright } 2023 All rights reserved.
 */

#include "GameCreationController.h"

/**
 * @brief Creates a new GameOptions object with given params
 * @param version
 * @param modeOptions
 * @param isExpert
 * @param aiMode
 * @param maxRounds
 * @return GameOptions*
 */
static GameOptions *createGameOption(unsigned int version, ModeOptions modeOptions, bool isExpert, bool aiMode, unsigned int maxRounds) {
  GameOptions * gameOptions = new GameOption();

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
static Player * createPlayer(std::string username, std::string lastTripDestination, std::chrono::year_month_day birthday) {
  Player * ply = new Player(username, lastTripDestination, birthday);

  return ply;
}

/**
 * @brief Create a new Game based on all the given parameters
 * @param gameOptions
 * @param players
 * @param board
 * @return Game*
 */
static Game *createGame(GameOptions * gameOptions, std::pair<Player*, Player*> players, Board * board) {
  Game * game = new Game(gameOptions, players, board);

  return game;
}
