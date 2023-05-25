/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/24/2023
 * @copyright Copyright 2023 All rights reserved.
 */

// You may need to build the project (run Qt uic code generator) to get "ui_CardSlot.h" resolved

#include "CardSlot.h"
#include "ui_CardSlot.h"

CardSlot::CardSlot(QWidget *parent) : QWidget(parent), ui(new Ui::CardSlot) {
  ui->setupUi(this);
}

void CardSlot::paintEvent(QPaintEvent* event) {
  QPainter painter(this);

  painter.setRenderHint(QPainter::Antialiasing);

  QRadialGradient gradient(width() / 2, height() / 2, qMin(width(), height()) / 2,
                           width() / 2, height() / 2);
  gradient.setColorAt(0, Qt::white);
  gradient.setColorAt(0.1, QColor("#55ffff"));
  gradient.setColorAt(1, QColor("#005757"));

  QPen pen;
  pen.setBrush(QBrush(gradient));
  pen.setWidth(5);

  painter.setPen(pen);
  painter.drawRect(rect().adjusted(0, 0, -1, -1));

  QWidget::paintEvent(event);
}

CardSlot::~CardSlot() {
  delete ui;
}
