/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/24/2023
 * @copyright Copyright 2023 All rights reserved.
 */

// You may need to build the project (run Qt uic code generator) to get "ui_CardSlot.h" resolved

#include "CardSlot.h"
#include "../../Style/Style.h"
#include "ui_CardSlot.h"

namespace View::Components {

CardSlot::CardSlot(QWidget *parent) : QWidget(parent), ui(new Ui::CardSlot) {
  setAttribute(Qt::WA_TranslucentBackground);
  ui->setupUi(this);
}

void CardSlot::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  if (!shouldRender) { /* draw transparent rectangle instead of the black lines */
    return;
  }

  QPen pen;
  pen.setColor(Style::dark());
  pen.setWidth(5);

  QRectF rectangle(0, 0, width(), height());

  painter.setPen(pen);
  painter.drawRect(rectangle);

  QWidget::paintEvent(event);
}

CardSlot::~CardSlot() {
  delete ui;
}
}// namespace View::Components
