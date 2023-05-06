/***
 * LO21: Shotten-Totten Project
 * @author: Roussel Pierre
 * @author: Santamaria Gabriel
 * @licence: TODO
 */

#ifndef LO21_PROJECT_CONSTANTS_H
#define LO21_PROJECT_CONSTANTS_H

enum class GameVersion {
  VERSION1,
  VERSION2,
};

enum class ModeOptions {
  normal,
  tactic,
};

enum class Rules {
  none,
};

enum class Combination {
  colorRun,
  threeOfAKind,
  color,
  run,
  none,
};

enum class Phase {
  play,
  claim,
  draw,
  pass,
};

#endif//LO21_PROJECT_CONSTANTS_H
