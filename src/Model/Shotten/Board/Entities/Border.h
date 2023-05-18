/**
* @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
* @date 5/10/2023
* @copyright Copyright 2023 All rights reserved.
*/

#ifndef LO21_PROJECT_BORDER_H
#define LO21_PROJECT_BORDER_H

#include "../../../../Constants/Constants.h"
#include "../../Combo.h"

namespace Model::Shotten::Board::Entities {
class Border {
protected:
  unsigned int id;
  Combo combo;
  Rules rules;
};
}// namespace Model::Shotten::Board::Entities
#endif//LO21_PROJECT_BORDER_H
