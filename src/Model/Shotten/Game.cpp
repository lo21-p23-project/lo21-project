//
// Created by Pierre Roussel on 4/17/23.
//

#include "Game.h"

using namespace Shotten;

Game *Game::game_ = nullptr;

Game::~Game() {
  delete currentRound_;
  delete board_;
}