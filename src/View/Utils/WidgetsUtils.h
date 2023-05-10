//
// Created by Pierre Roussel on 5/9/23.
//

#ifndef LO21_PROJECT_WIDGETSUTILS_H
#define LO21_PROJECT_WIDGETSUTILS_H

#include "../../Constants/Constants.h"
#include "../Constants/Widgets.h"

#include <string>

std::string widgetToString(Widgets widget);

std::string gameVersionToString(GameVersion gameVersion);

struct NavigationParams {
  GameVersion gameVersion;
};

#endif//LO21_PROJECT_WIDGETSUTILS_H
