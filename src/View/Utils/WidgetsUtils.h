//
// Created by Pierre Roussel on 5/9/23.
//

#ifndef LO21_PROJECT_WIDGETSUTILS_H
#define LO21_PROJECT_WIDGETSUTILS_H

#include "../../Constants/Constants.h"
#include "../Constants/WidgetsOptions.h"

#include <string>

using namespace View::Constants;

namespace View::Utils {

std::string widgetToString(WidgetsOptions widget);

std::string gameVersionToString(GameVersion gameVersion);

struct NavigationParams {
  GameVersion gameVersion;
};
}// namespace View::Utils

#endif//LO21_PROJECT_WIDGETSUTILS_H
