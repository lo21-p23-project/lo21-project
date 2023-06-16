//
// Created by Pierre Roussel on 6/1/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Hand.h" resolved

#include "HandWidget.h"
#include "ui_HandWidget.h"

// For debugging purposes
#include <iostream>

namespace View::Components {

HandWidget::HandWidget(CardManager *cardManager, QWidget *parent) : QWidget(parent), ui(new Ui::HandWidget) {
  ui->setupUi(this);

  const GameVersion gameVersion = GameplayController::getGameOption()->version;

  QGridLayout *mainLayout = new QGridLayout;

  for (int i = 0; i < (gameVersion == GameVersion::VERSION1 ? 6 : 7); i++) {
    slots_.push_back(new CardSlot(CardSlotType::HAND, this));

    cardManager->registerCardSlot(slots_[i]);
    mainLayout->addWidget(slots_[i], 0, i);
  }

  this->setLayout(mainLayout);
}

HandWidget::~HandWidget() {
  delete ui;
}
}// namespace View::Components