//
// Created by Pierre Roussel on 4/17/23.
//

#include "Game.h"

using namespace Model::Shotten;

Game *Game::game_ = nullptr;

namespace Model::Shotten {

Game::~Game() {
  delete currentRound_;
  delete board_;
}
}// namespace Model::Shotten