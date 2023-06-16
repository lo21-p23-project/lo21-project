//
// Created by Pierre Roussel on 5/19/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameWidget.h" resolved

#include "GameWidget.h"
#include "ui_GameWidget.h"

namespace View::Widgets {

GameWidget::GameWidget(WidgetsOptions widget, int index, QWidget *parent) : cardManager_(new CardManager(this)), StackedChildWidget(widget, index, parent), ui(new Ui::GameWidget) {
  ui->setupUi(this);

  // Get the GameOptions
  const std::shared_ptr<GameOptions> gameOptions = getGameOption();
  const ModeOptions modeOptions = gameOptions->modeOptions;

  QWidget *mainWidget = new QWidget;
  QHBoxLayout *mainLayout = new QHBoxLayout;

  // Related to the decks
  QWidget *decksWidget = new QWidget;
  QVBoxLayout *decksLayout = new QVBoxLayout;

  if (modeOptions == ModeOptions::TACTIC) {
    QLabel *discardDeckLabel = new QLabel("Discard deck");
    decksLayout->addWidget(discardDeckLabel, 0, Qt::AlignHCenter);
    CardSlot *discardDeckWidget = new CardSlot(CardSlotType::DECK, this);
    cardManager_->registerCardSlot(discardDeckWidget);
    decksLayout->addWidget(discardDeckWidget, 2);

    QLabel *tacticDeckLabel = new QLabel("Tactic deck");
    decksLayout->addWidget(tacticDeckLabel, 0, Qt::AlignHCenter);
    DeckWidget *tacticDeckWidget = new DeckWidget(DeckType::TACTIC);
    decksLayout->addWidget(tacticDeckWidget, 2);
  }

  QLabel *normalDeckLabel = new QLabel("Normal deck");
  decksLayout->addWidget(normalDeckLabel, 0, Qt::AlignHCenter);
  DeckWidget *normalDeckWidget = new DeckWidget(DeckType::NORMAL);
  decksLayout->addWidget(normalDeckWidget, 2);

  decksWidget->setLayout(decksLayout);

  // Related to the board
  QWidget *boardWidget = new QWidget;
  QVBoxLayout *boardLayout = new QVBoxLayout;

  opponentHandWidget_ = new HandWidget(cardManager_);
  boardLayout->addWidget(opponentHandWidget_, 1);

  borderWidget_ = new BorderWidget(cardManager_);
  boardLayout->addWidget(borderWidget_, 3);

  playerHandWidget_ = new HandWidget(cardManager_);
  boardLayout->addWidget(playerHandWidget_, 1);

  boardWidget->setLayout(boardLayout);

  // Related to the actions
  QWidget *actionsWidget = new QWidget;
  QVBoxLayout *actionsLayout = new QVBoxLayout;

  playerNameLabel_ = new QLabel("col-roussel");
  actionsLayout->addWidget(playerNameLabel_, 0, Qt::AlignCenter);

  Button *passButton = new Button("Pass");
  actionsLayout->addWidget(passButton, 0);

  actionsLayout->setAlignment(Qt::AlignBottom);
  actionsWidget->setLayout(actionsLayout);

  // Add the widgets to the main layout
  mainLayout->addWidget(decksWidget, 2);
  mainLayout->addWidget(boardWidget, 10);
  mainLayout->addWidget(actionsWidget, 1);

  // Set the layout to the main widget
  mainWidget->setLayout(mainLayout);

  // Initialize player's hand
  connect(this, &GameWidget::requestInitializePlayersHandsSignals, normalDeckWidget, &DeckWidget::requestInitializePlayersHands);
  emit requestInitializePlayersHandsSignals(ModeOptions::NORMAL);

  this->layout()->addWidget(mainWidget);
}

GameWidget::~GameWidget() {
  delete ui;
  delete cardManager_;
}
}// namespace View::Widgets
