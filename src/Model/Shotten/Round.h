//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_ROUND_H
#define LO21_PROJECT_ROUND_H

#include <string>
#include <utility>

#include "Turn.h"

namespace Model::Shotten {
class Round {
private:
  unsigned int id;
  std::string winner;
  Turn turn;

public:
  Round() : id(0), turn(0, nullptr, Phase::PLAY) {}
  Round(unsigned int id, Turn turn)
      : id(id), turn(std::move(turn)) {}

  unsigned int getId() const { return id; }
  std::string getWinner() const { return winner; }
  Turn getTurn() const { return turn; }
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_ROUND_H
