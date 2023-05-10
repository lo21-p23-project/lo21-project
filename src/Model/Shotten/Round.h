//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_ROUND_H
#define LO21_PROJECT_ROUND_H

#include <string>

#include "Turn.h"

namespace Model::Shotten {
class Round {
private:
  unsigned int id;
  std::string winner;
  Turn turns;

public:
  Round();
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_ROUND_H
