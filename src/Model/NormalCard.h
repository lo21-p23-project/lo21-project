/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_NORMALCARD_H
#define LO21_PROJECT_NORMALCARD_H

#include <string>

#include "Card.h"

class NormalCard : public Card {
private:
  unsigned int value;
  std::string color;

public:
};

#endif//LO21_PROJECT_NORMALCARD_H
