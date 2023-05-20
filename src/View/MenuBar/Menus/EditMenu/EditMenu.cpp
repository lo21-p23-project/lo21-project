//
// Created by Pierre Roussel on 4/30/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_EditMenu.h" resolved

#include "EditMenu.h"
#include "ui_EditMenu.h"

namespace View::Menus {
EditMenu::EditMenu(QString title) : QMenu(title), ui(new Ui::EditMenu) {
  ui->setupUi(this);

  // Create the "Edit" menu
  this->addAction("Undo");
  this->addAction("Redo");
  this->addSeparator();
  this->addAction("Cut");
  this->addAction("Copy");
  this->addAction("Paste");
  this->addAction("Delete");
  this->addAction("Select All");
}

EditMenu::~EditMenu() {
  delete ui;
}
}// namespace View::Menus
