//
// Created by Pierre Roussel on 5/10/23.
//

#include "WidgetsUtils.h"

namespace View::Utils {

/**
 * @brief Converts a WidgetsOptions enum to a string
 * @param widget The WidgetsOptions enum to convert
 * @return The string representation of the WidgetsOptions enum
 */
std::string widgetToString(const WidgetsOptions widget) {
  switch (widget) {
  case WidgetsOptions::HOME:
    return "Home";
  case WidgetsOptions::GAME_OPTIONS:
    return "GameOptions";
  case WidgetsOptions::GAME:
    return "Game";
  default:
    return "Unknown";
  }
}

/**
 * @brief Converts a GameVersion enum to a string
 * @param gameVersion The GameVersion enum to convert
 * @return The string representation of the GameVersion enum
 */
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
}// namespace View::Utils
