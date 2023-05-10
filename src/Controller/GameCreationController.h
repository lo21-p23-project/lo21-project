
/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/10/2023
 * @copyright Copyright } 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H
#define LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H

#include "../Model/GameOptions.h"
#include "../Model/Game.h"

namespace Controller {
class GameCreationController {
public:
  static GameOptions *createGameOption(unsigned int, ModeOptions, bool, bool, unsigned int);
  static Player *createPlayer(std::string, std::string, std::chrono::year_month_day);
  static Game *createGame(GameOptions *, std::pair<Player*, Player*>, Board *);
};
}// namespace Controller
#endif//LO21_PROJECT_SRC_CONTROLLER_GAMECREATIONCONTROLLER_H
