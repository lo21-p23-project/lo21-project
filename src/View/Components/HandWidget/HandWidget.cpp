//
// Created by Pierre Roussel on 6/1/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Hand.h" resolved

#include "HandWidget.h"
#include "ui_HandWidget.h"

// For debugging purposes
#include <iostream>

namespace View::Components {

HandWidget::HandWidget(const string playerUsernameHand, CardManager *cardManager, QWidget *parent) : playerUsernameHand_(playerUsernameHand), cardManager_(cardManager), QWidget(parent), ui(new Ui::HandWidget) {
  ui->setupUi(this);

  const GameVersion gameVersion = GameplayController::getGameOption()->version;

  QGridLayout *mainLayout = new QGridLayout;

  for (int i = 0; i < (gameVersion == GameVersion::VERSION1 ? 6 : 7); i++) {
    slots_.push_back(new CardSlot(CardSlotType::HAND, this));

    cardManager_->registerCardSlot(slots_[i]);
    mainLayout->addWidget(slots_[i], 0, i);
  }

  this->setLayout(mainLayout);
}

HandWidget::~HandWidget() {
  delete ui;
}

/**
 * @brief HandWidget::receiveNormalCardDrawnSignal
 * @details Adds a card to the hand when a normal card is drawn.
 * @param card
 * @param playerName
 * @return void
 */
void HandWidget::receiveNormalCardDrawn(shared_ptr<NormalCard> card, string playerName) {
  if (playerName != playerUsernameHand_) {
    return;
  }
  cout << "HandWidget - receiveNormalCardDrawnSignal for " << playerUsernameHand_ << endl;

  DragableCard *draggableCard = new DragableCard(slots_[0]->pos(), slots_[0]->size(), cardManager_, this->parentWidget());
  this->parentWidget()->layout()->addWidget(draggableCard);
}

/**
 * @brief HandWidget::receiveInitializePlayersHands
 * @details Adds a card to the hand when a tactic card is drawn.
 * @param cards
 * @param playerName
 * @return void
 */
void HandWidget::receiveTacticCardDrawn(shared_ptr<Model::Shotten::TacticCard> card, std::string playerName) {
  if (playerName != playerUsernameHand_) {
    return;
  }
  cout << "HandWidget - receiveTacticCardDrawnSignal for " << playerUsernameHand_ << endl;
}

/**
 * @brief HandWidget::receiveInitializePlayersHands
 * @details Initializes the hand when the game starts.
 * @param cards
 * @param playerName
 * @return void
 */
void HandWidget::receiveInitializePlayersHands(shared_ptr<vector<shared_ptr<NormalCard>>> cards, string playerName) {
  if (playerName != playerUsernameHand_) {
    return;
  }
  cout << "HandWidget - receiveInitializePlayersHands for " << playerUsernameHand_ << endl;
}
}// namespace View::Components