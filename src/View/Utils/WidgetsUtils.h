//
// Created by Pierre Roussel on 5/9/23.
//

#ifndef LO21_PROJECT_WIDGETSUTILS_H
#define LO21_PROJECT_WIDGETSUTILS_H

#include "../../Constants/Constants.h"
#include "../../Model/Shotten/Game.h"
#include "../../Model/Shotten/GameOptions.h"
#include "../../Model/Shotten/Player/Player.h"
#include "../Constants/CardSlotType.h"
#include "../Constants/WidgetsOptions.h"

#include <string>

using namespace View::Constants;
using namespace Model::Shotten;

namespace View::Utils {

std::string widgetToString(WidgetsOptions widget);

std::string gameVersionToString(GameVersion gameVersion);

std::string cardSlotTypesToString(CardSlotType cardSlotTypes);

struct NavigationParams {
  GameVersion gameVersion;
  int playerNumber;
  std::shared_ptr<GameOptions> gameOptions;
  std::shared_ptr<Player::Player> player;
  Game *game;
};
}// namespace View::Utils

#endif//LO21_PROJECT_WIDGETSUTILS_H