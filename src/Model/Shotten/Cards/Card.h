/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

#ifndef LO21_PROJECT_CARD_H
#define LO21_PROJECT_CARD_H

#include <string>
#include "../../../Constants/Constants.h"

#define MAX_CARD_VALUE 11

namespace Model::Shotten {
class Card {
protected:
  std::string name;
  std::string description;

  int value_;
  Color color_;

public:
  Card() = default;
  Card(const Card &other) = default;

  int getValue() const { return this->value_; }
  Color getColor() const { return this->color_; }
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_CARD_H
