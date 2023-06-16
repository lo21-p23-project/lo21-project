//
// Created by Pierre Roussel on 6/15/23.
//

#ifndef LO21_PROJECT_GAMECONTROLLER_H
#define LO21_PROJECT_GAMECONTROLLER_H

#include "../Model/Shotten/Game.h"

using namespace Model::Shotten;

namespace Controller {

static std::shared_ptr<GameOptions> getGameOption() {
  return Game::getInstance()->getGameOption();
}


}// namespace Controller

#endif//LO21_PROJECT_GAMECONTROLLER_H
