//
// Created by Pierre Roussel on 5/19/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameWidget.h" resolved

#include "GameWidget.h"
#include "ui_GameWidget.h"

namespace View::Widgets {

GameWidget::GameWidget(const NavigationParams &navigationParams, WidgetsOptions widget, int index, QWidget *parent) : cardManager(new CardManager(this)), StackedChildWidget(widget, index, parent), ui(new Ui::GameWidget) {
  ui->setupUi(this);

  QWidget *mainWidget = new QWidget;
  QHBoxLayout *mainLayout = new QHBoxLayout;

  // Related to the decks
  QWidget *decksWidget = new QWidget;
  QVBoxLayout *decksLayout = new QVBoxLayout;

  DeckWidget *discardDeckWidget = new DeckWidget(GameVersion::VERSION1);
  decksLayout->addWidget(discardDeckWidget, 0);

  DeckWidget *tacticDeckWidget = new DeckWidget(GameVersion::VERSION1);
  decksLayout->addWidget(tacticDeckWidget, 0);

  DeckWidget *normalDeckWidget = new DeckWidget(GameVersion::VERSION1);
  decksLayout->addWidget(normalDeckWidget, 0);

  decksWidget->setLayout(decksLayout);

  // Related to the board
  QWidget *boardWidget = new QWidget;
  QVBoxLayout *boardLayout = new QVBoxLayout;

  HandWidget *playerWidget = new HandWidget(cardManager, GameVersion::VERSION1);
  boardLayout->addWidget(playerWidget, 1);

  BorderWidget *borderWidget = new BorderWidget(cardManager, GameVersion::VERSION1);
  boardLayout->addWidget(borderWidget, 3);

  HandWidget *opponentWidget = new HandWidget(cardManager, GameVersion::VERSION1);
  boardLayout->addWidget(opponentWidget, 1);

  boardWidget->setLayout(boardLayout);

  // Related to the actions
  QWidget *actionsWidget = new QWidget;
  QVBoxLayout *actionsLayout = new QVBoxLayout;

  QLabel *playerName = new QLabel("col-roussel");
  actionsLayout->addWidget(playerName, 0, Qt::AlignCenter);

  Button *passButton = new Button("Pass");
  actionsLayout->addWidget(passButton, 0);

  actionsLayout->setAlignment(Qt::AlignBottom);
  actionsWidget->setLayout(actionsLayout);

  // Add the widgets to the main layout
  mainLayout->addWidget(decksWidget, 2);
  mainLayout->addWidget(boardWidget, 10);
  mainLayout->addWidget(actionsWidget, 0);

  // Set the layout to the main widget
  mainWidget->setLayout(mainLayout);

  this->layout()->addWidget(mainWidget);
}

GameWidget::~GameWidget() {
  delete ui;
  delete cardManager;
}
}// namespace View::Widgets
