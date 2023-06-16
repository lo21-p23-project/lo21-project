//
// Created by Pierre Roussel on 6/6/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BorderWidget.h" resolved

#include "BorderWidget.h"
#include "ui_BorderWidget.h"

namespace View::Components {

BorderWidget::BorderWidget(CardManager *cardManager, QWidget *parent) : QWidget(parent), ui(new Ui::BorderWidget) {
  ui->setupUi(this);

  const GameVersion gameVersion = GameplayController::getGameOption()->version;

  QGridLayout *mainLayout = new QGridLayout;

  const int numberOfCards = gameVersion == GameVersion::VERSION1 ? 9 : 7;
  for (int i = 0; i < numberOfCards; i++) {
    slots_.push_back(new CardSlot(CardSlotType::BORDER, this));
    ComboWidget *comboUp = new ComboWidget(cardManager, this);
    ComboWidget *comboDown = new ComboWidget(cardManager, this);

    cardManager->registerCardSlot(slots_[i]);

    mainLayout->addWidget(comboUp, 0, i, 2, 1);
    mainLayout->addWidget(slots_[i], 4, i, 1, 1);
    mainLayout->addWidget(comboDown, 5, i, 2, 1);
  }

  this->setLayout(mainLayout);
}

BorderWidget::~BorderWidget() {
  delete ui;
}
}// namespace View::Components