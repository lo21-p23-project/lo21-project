/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

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
