//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_COMBO_H
#define LO21_PROJECT_COMBO_H

#include <string>
#include <vector>

#include "../../Constants/Constants.h"
#include "Cards/Card.h"

namespace Model::Shotten {
class Combo {
private:
  std::string engagedBy;
  std::vector<Card> cards;
  Combination combination;
  unsigned int sum;
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_COMBO_H
