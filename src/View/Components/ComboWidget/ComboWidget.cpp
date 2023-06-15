//
// Created by Pierre Roussel on 6/6/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ComboWidget.h" resolved

#include "ComboWidget.h"
#include "ui_ComboWidget.h"

namespace View::Components {

ComboWidget::ComboWidget(CardManager *cardManager, QWidget *parent) : QWidget(parent), ui(new Ui::ComboWidget) {
  ui->setupUi(this);

  QGridLayout *mainLayout = new QGridLayout;

  const int numberOfCards = 3;
  for (int i=0; i < numberOfCards; i++) {
    slots_.push_back(new CardSlot(this));

    mainLayout->addWidget(slots_[i], i, 0, 5, 1);
    cardManager->registerCardSlot(slots_[i]);
  }

  this->setLayout(mainLayout);
}

ComboWidget::~ComboWidget() {
  delete ui;
}
}// namespace View::Components