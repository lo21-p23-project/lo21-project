//
// Created by Pierre Roussel on 5/19/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameWidget.h" resolved

#include "GameWidget.h"
#include "../../Components/CardManager/CardManager.h"
#include "../../Components/DragableCard/DragableCard.h"
#include "../../Components/CardSlot/CardSlot.h"
#include "ui_GameWidget.h"

namespace View::Widgets {

GameWidget::GameWidget(WidgetsOptions widget, int index, QWidget *parent) : StackedChildWidget(widget, index, parent), ui(new Ui::GameWidget) {
  ui->setupUi(this);

  CardManager* cardManager = new CardManager(this);

  CardSlot* slot1 = new CardSlot(this);
  slot1->setGeometry(QRect(QPoint(100, 100), QSize(100, 150)));
  CardSlot* slot2 = new CardSlot(this);
  slot2->setGeometry(QRect(QPoint(300, 100), QSize(100, 150)));

  cardManager->registerCardSlot(slot1);
  cardManager->registerCardSlot(slot2);

  DragableCard* card = new DragableCard(this);
  card->setGeometry(QRect(QPoint(100, 100), QSize(100, 150)));
  card->setCardManager(cardManager);
}

GameWidget::~GameWidget() {
  delete ui;
}
}// namespace View::Widgets
