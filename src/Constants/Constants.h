//
// Created by Pierre Roussel on 4/30/23.
//

#ifndef LO21_PROJECT_CONSTANTS_H
#define LO21_PROJECT_CONSTANTS_H

enum class GameVersion {
  VERSION1,
  VERSION2,
};

enum class ModeOptions {
  NORMAL,
  TACTIC,
};

enum class Rules {
  NONE,
};

enum class Combination {
  COLOR_RUN,
  THREE_OF_A_KIND,
  COLOR,
  RUN,
  NONE,
};

enum class Phase {
  PLAY,
  CLAIM,
  DRAW,
  PASS,
};

#endif//LO21_PROJECT_CONSTANTS_H
