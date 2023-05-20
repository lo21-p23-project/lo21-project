//
// Created by Pierre Roussel on 4/30/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ViewMenu.h" resolved

#include "ViewMenu.h"
#include "ui_ViewMenu.h"

namespace View::Menus {

ViewMenu::ViewMenu(QString title) : QMenu(title), ui(new Ui::ViewMenu) {
  ui->setupUi(this);

  // Create the "View" menu
  this->addAction("Actual Size");
  this->addAction("Zoom In");
  this->addAction("Zoom Out");
  this->addSeparator();
  this->addAction("Go Back");
  this->addAction("Go Forward");
}

ViewMenu::~ViewMenu() {
  delete ui;
}
}// namespace View::Menus
