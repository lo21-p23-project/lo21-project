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
  const std::shared_ptr<GameOptions> gameOptions = GameplayController::getGameOption();
  const ModeOptions modeOptions = gameOptions->modeOptions;

  // Get the Players
  const pair<shared_ptr<Player::Player>, shared_ptr<Player::Player>> players = GameplayController::getPlayers();
  // player_ = players.second == GameplayController::getPlayerTurn() ?
  //       players.second :
  //       players.first;
  // opponent_ = players.second == GameplayController::getPlayerTurn() ?
  //       players.first :
  //       players.second;
  // TODO: Remove this - Waiting for GameplayController::getPlayerTurn() to be implemented
  player_ = players.first;
  opponent_ = players.second;

  QWidget *mainWidget = new QWidget;
  QHBoxLayout *mainLayout = new QHBoxLayout;

  CardManager *cardManager = new CardManager(this);

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

  opponentHandWidget_ = new HandWidget(opponent_->getUsername(), cardManager_);
  boardLayout->addWidget(opponentHandWidget_, 1);

  borderWidget_ = new BorderWidget(cardManager_);
  boardLayout->addWidget(borderWidget_, 3);

  playerHandWidget_ = new HandWidget(player_->getUsername(), cardManager_);
  boardLayout->addWidget(playerHandWidget_, 1);

  boardWidget->setLayout(boardLayout);

  // Related to the actions
  QWidget *actionsWidget = new QWidget;
  QVBoxLayout *actionsLayout = new QVBoxLayout;

  playerNameLabel_ = new QLabel(player_->getUsername().c_str());
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
  connect(this, &GameWidget::requestInitializePlayersHandsSignal, normalDeckWidget, &DeckWidget::requestInitializePlayersHands);
  connect(normalDeckWidget, &DeckWidget::normalCardDrawnForInitilization, playerHandWidget_, &HandWidget::receiveInitializePlayersHands);
  connect(normalDeckWidget, &DeckWidget::normalCardDrawnForInitilization, opponentHandWidget_, &HandWidget::receiveInitializePlayersHands);
  connect(normalDeckWidget, &DeckWidget::checkPlayerCanReceiveCardSignal, playerHandWidget_, &HandWidget::checkPlayerCanReceiveCard);
  connect(normalDeckWidget, &DeckWidget::normalCardDrawn, playerHandWidget_, &HandWidget::receiveNormalCardDrawn);
  connect(playerHandWidget_, &HandWidget::playerCanReceiveCardSignal, normalDeckWidget, &DeckWidget::canPlayerReceiveCard);
  connect(passButton, &Button::clicked, this, &GameWidget::passButtonClicked);
  emit requestInitializePlayersHandsSignal(ModeOptions::NORMAL);

  this->layout()->addWidget(mainWidget);
}

GameWidget::~GameWidget() {
  delete ui;
  delete cardManager_;
}

void GameWidget::passButtonClicked() {
  cout << "GameWidget - " << player_->getUsername() << " passed is turn" << endl;

  // TODO: Remove this - Waiting for GameplayController::passPlayerTurn() to be implemented
  // GameplayController::passPlayerTurn();
  auto previousPlayer = player_;
  player_ = opponent_;
  opponent_ = previousPlayer;

  // Updating the Layout
  playerNameLabel_->setText(player_->getUsername().c_str());
  playerHandWidget_->setPlayerUsernameHand(player_->getUsername());
  opponentHandWidget_->setPlayerUsernameHand(opponent_->getUsername());

  update();
}
}// namespace View::Widgets