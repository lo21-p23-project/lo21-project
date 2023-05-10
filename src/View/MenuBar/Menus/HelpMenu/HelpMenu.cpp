//
// Created by Pierre Roussel on 4/30/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_HelpMenu.h" resolved

#include "HelpMenu.h"
#include "ui_HelpMenu.h"

HelpMenu::HelpMenu(QString title, QWidget *parent) : QMenu(title), ui(new Ui::HelpMenu), parent(parent) {
  ui->setupUi(this);

  // Create the "Help" menu
  QMenu *rulesMenu = this->addMenu(tr("&Rules"));
  QAction *rulesVersion1Action = new QAction(tr("&Version 1"));
  connect(rulesVersion1Action, &QAction::triggered, [=]() {
    this->openRules(GameVersion::VERSION1);
  });
  rulesMenu->addAction(rulesVersion1Action);
  QAction *rulesVersion2Action = new QAction(tr("&Version 2"));
  connect(rulesVersion2Action, &QAction::triggered, [=]() {
    this->openRules(GameVersion::VERSION2);
  });
  rulesMenu->addAction(rulesVersion2Action);

  this->addAction("Strategy");
}

HelpMenu::~HelpMenu() {
  delete ui;
}

void HelpMenu::openRules(GameVersion gameVersion) {
  WorkInProgressWidget *rulesWidget = new WorkInProgressWidget(parent);

  //  QWidget *rulesWidget = new QWidget(parent);
  //  // Name the window according to the game version
  //  rulesWidget->setWindowTitle(
  //      QString(gameVersion == GameVersion::VERSION1 ? "Original" : "Remastered") +
  //      tr(" Version")
  //      );
  //
  //  // Fetch the rules according to the game version
  //  switch (gameVersion) {
  //    case GameVersion::VERSION2:
  //      break;
  //    case GameVersion::VERSION1:
  //    default:
  //      break;
  //  }

  rulesWidget->show();
}