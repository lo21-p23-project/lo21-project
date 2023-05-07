//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_GAMEOPTIONS_H
#define LO21_PROJECT_GAMEOPTIONS_H

#include "../../Constants/Constants.h"

namespace Model::Shotten {
struct GameOptions {
  unsigned int version;
  ModeOptions modeOptions;
  bool isExpert;
  bool aiMode;
  unsigned int maxRounds;
};
}// namespace Model::Shotten

#endif//LO21_PROJECT_GAMEOPTIONS_H
