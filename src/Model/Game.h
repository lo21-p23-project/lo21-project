//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_GAME_H
#define LO21_PROJECT_GAME_H

#include <vector>
#include "GameOptions.h"
#include "Round.h"
#include "Player.h"
#include "Board.h"

class Game {
private:
  GameOptions gameOptions;
  std::vector<Player> players;
  std::vector<Round> rounds;
  Board board;
public:
};


#endif //LO21_PROJECT_GAME_H
