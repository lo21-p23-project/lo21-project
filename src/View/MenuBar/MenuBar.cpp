//
// Created by Pierre Roussel on 4/30/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MenuBar.h" resolved

#include "MenuBar.h"
#include "ui_MenuBar.h"

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent), ui(new Ui::MenuBar) {
  ui->setupUi(this);

  // TODO: Create the "Settings" menu
  // Don't understand how it is working
  // Need to investigate deeper
  //  QMenu *settingsMenu = new QMenu(tr("&Settings"));
  //  settingsMenu->addAction("About");
  //  settingsMenu->addAction("Check for Updates...");
  //  settingsMenu->addAction("Preferences...");
  //  this->addMenu(settingsMenu);

  // Create the "File" menu
  FileMenu *fileMenu = new FileMenu;
  this->addMenu(fileMenu);
  // Create the "Edit" menu
  EditMenu *editMenu = new EditMenu;
  this->addMenu(editMenu);
  // Create the "View" menu
  ViewMenu *viewMenu = new ViewMenu;
  this->addMenu(viewMenu);
  // Create the "Help" menu
  HelpMenu *helpMenu = new HelpMenu;
  this->addMenu(helpMenu);
}

MenuBar::~MenuBar() {
  delete ui;
}
