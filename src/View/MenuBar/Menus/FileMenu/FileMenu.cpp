//
// Created by Pierre Roussel on 4/30/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FileMenu.h" resolved

#include "FileMenu.h"
#include "ui_FileMenu.h"


FileMenu::FileMenu(QString title) :
    QMenu(title), ui(new Ui::FileMenu) {
  ui->setupUi(this);

  // Create the "File" menu
  this->addAction("New Profile");
  this->addAction("Import Profile");
  this->addAction("Export Profile");
  this->addSeparator();
  this->addAction("New Game");
  this->addAction("Open Game");
  this->addAction("Recent Game");
  this->addAction("Save Game");
}

FileMenu::~FileMenu() {
  delete ui;
}
