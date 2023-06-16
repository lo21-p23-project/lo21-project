//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_NORMALCARD_H
#define LO21_PROJECT_NORMALCARD_H

#include <string>

#include "../Card.h"

namespace Model::Shotten {
class NormalCard : public Card {
public:
  NormalCard(unsigned int value, Color color);
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_NORMALCARD_H