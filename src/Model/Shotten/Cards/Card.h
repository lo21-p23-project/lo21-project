//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_CARD_H
#define LO21_PROJECT_CARD_H

#include <string>

namespace Model::Shotten {
class Card {
protected:
  const std::string name;
  const std::string description;

public:
  Card() = default;
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_CARD_H
