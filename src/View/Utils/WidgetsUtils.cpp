//
// Created by Pierre Roussel on 5/10/23.
//

#include "WidgetsUtils.h"

/**
 * @brief Converts a Widgets enum to a string
 * @param widget The Widgets enum to convert
 * @return The string representation of the Widgets enum
 */
std::string widgetToString(const Widgets widget) {
  switch (widget) {
  case Widgets::HOME:
    return "Home";
  case Widgets::GAME_OPTIONS:
    return "GameOptions";
  case Widgets::GAME:
    return "Game";
  default:
    return "Unknown";
  }
}

std::string gameVersionToString(const GameVersion gameVersion) {
  switch (gameVersion) {
  case GameVersion::VERSION1:
    return "Original";
  case GameVersion::VERSION2:
    return "Remastered";
  default:
    return "Unknown";
  }
}
