/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 6/16/2023
 * @copyright Copyright 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_GAMEPLAYCONTROLLER_H
#define LO21_PROJECT_GAMEPLAYCONTROLLER_H

#include "../Model/Shotten/Game.h"

namespace Controller {

class GameplayController {
public:
  /**
  * Gets which player it's the voice to
  * @return
  */
  static auto getPlayerTurn() {
    auto game = Game::getInstance();

    return game->getRound()->getTurn()->getCurrentPlayerVoice();
  }

  /**
  * Pass the turn of the current player
  * @return void
  */
  static void passPlayerTurn() {
    auto game = Game::getInstance();
    auto player = game->getRound()->getTurn()->getCurrentPlayerVoice();
    /* we send the message to the player that he passed his turn */
    game->getRound()->getTurn()->trigger(std::make_pair(player, Phase::PASS));
  }

  /**
  * Gets the game options
  * @return std::shared_ptr<GameOptions>
  */
  static std::shared_ptr<GameOptions> getGameOption() {
    return Game::getInstance()->getGameOption();
  }

  // TODO: Make a function call for when a player plays a card
};
}// namespace Controller

#endif//LO21_PROJECT_GAMEPLAYCONTROLLER_H
