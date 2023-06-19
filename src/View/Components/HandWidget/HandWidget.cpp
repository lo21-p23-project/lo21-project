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

  int i = 0;
  while (slots_[i]->isFree() == false) {
    i++;
    if (i == slots_.size()) {
      cout << "HandWidget - receiveNormalCardDrawnSignal - no free slots for " << playerUsernameHand_ << endl;
      return;
    }
  }

  DragableCard *draggableCard = new DragableCard({0, 0}, slots_[i]->size(), cardManager_, this->parentWidget()->parentWidget());
  slots_[i]->layout()->setContentsMargins(0, 0, 0, 0);
  slots_[i]->layout()->addWidget(draggableCard);
  slots_[i]->setIsFree(false);
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

  for (int i = 0; i < cards->size(); i++) {
//    DragableCard *draggableCard = new DragableCard({0, 0}, slots_[0]->size(), cardManager_, this->parentWidget()->parentWidget());
//    slots_[i]->layout()->setContentsMargins(0, 0, 0, 0);
//    slots_[i]->layout()->addWidget(draggableCard);
  }
}

void HandWidget::checkPlayerCanReceiveCard(string playerName) {
  if (playerName != playerUsernameHand_) {
    return;
  }

  bool canReceive = false;
  int i = 0;
  while (i < slots_.size() && !canReceive) {
      if (slots_[i]->isFree()) {
      canReceive = true;
      }
      i++;
  }

  emit playerCanReceiveCardSignal(canReceive);
}
}// namespace View::Components