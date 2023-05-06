/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_GAME_H
#define LO21_PROJECT_GAME_H

#include "Board.h"
#include "GameOptions.h"
#include "Player.h"
#include "Round.h"
#include <vector>

class Game {
private:
  GameOptions gameOptions;
  std::vector<Player> players;
  std::vector<Round> rounds;
  Board board;

public:
};

#endif//LO21_PROJECT_GAME_H
