/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_COMBO_H
#define LO21_PROJECT_COMBO_H

#include <string>
#include <vector>

#include "../Constants/Constants.h"
#include "Card.h"

class Combo {
private:
  std::string engagedBy;
  std::vector<Card> cards;
  Combination combination;
  unsigned int sum;
};

#endif//LO21_PROJECT_COMBO_H
