//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_BORDER_H
#define LO21_PROJECT_BORDER_H

#include "../../../../Constants/Constants.h"
#include "../../Combo.h"

namespace Model::Shotten::Entities {
class Border {
protected:
  unsigned int id;
  Combo combo;
  Rules rules;
};
}// namespace Model::Shotten::Entities
#endif//LO21_PROJECT_BORDER_H
