/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/24/2023
 * @copyright Copyright 2023 All rights reserved.
 */

// You may need to build the project (run Qt uic code generator) to get "ui_CardSlot.h" resolved

#include "CardSlot.h"
#include "ui_CardSlot.h"

namespace View::Components {

CardSlot::CardSlot(const CardSlotType cardSlotType, QWidget *parent) : cardSlotType_(cardSlotType), QWidget(parent), ui(new Ui::CardSlot) {
  setAttribute(Qt::WA_TranslucentBackground);
  ui->setupUi(this);

  QHBoxLayout *mainLayout = new QHBoxLayout;

  this->setLayout(mainLayout);
}

void CardSlot::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  //  if (!shouldRender) { /* draw transparent rectangle instead of the black lines */
  //    return;
  //  }

  const qreal radius = 5.0;
  painter.setPen(Style::dark());
  painter.drawRoundedRect(
      QRectF(rect()).adjusted(
          0.5, 0.5, -0.5, -0.5),
      radius, radius);
}

CardSlot::~CardSlot() {
  delete ui;
}
}// namespace View::Components
