
/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/10/2023
 * @copyright Copyright } 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H
#define LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H

#include "../Model/Shotten/GameOptions.h"
#include "../Model/Shotten/Game.h"

using namespace Model::Shotten;

namespace Controller {
class GameCreationController {
public:
  GameOptions *createGameOption(unsigned int, ModeOptions, bool, bool, unsigned int);
  Player::Player *createPlayer(std::string, std::string, std::chrono::year_month_day);
  Game *createGame(GameOptions *, std::pair<Player::Player*, Player::Player*>, Board *);
};
}
#endif//LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H
