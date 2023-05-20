//
// Created by Pierre Roussel on 5/12/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BackButton.h" resolved

#include "BackButton.h"
#include "ui_BackButton.h"

namespace View::Components {

BackButton::BackButton(QWidget *parent) : QPushButton(parent), ui(new Ui::BackButton) {
  ui->setupUi(this);

  setAttribute(Qt::WA_Hover);
}

BackButton::~BackButton() {
  delete ui;
}

void BackButton::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  // Another advantage o QStyle: custom widgets can share code
  // with it (here just the color repository, but we could share more code
  // if needed)
  // With QSS, we can't use QSS to style our custom widget
  if (!isEnabled()) {
    painter.setPen(Style::dark());
    painter.setOpacity(0.5);
  } else if (underMouse() || hasFocus()) {
    painter.setPen(Style::lightBlue());
    painter.setOpacity(0.8);
  } else {
    painter.setPen(Style::dark());
  }

  painter.setBrush(Style::backgroundColorCard());
  QRect valueRect = rect().adjusted(
      1, 1,
      -1, -1);
  valueRect.setWidth(valueRect.height());// Must be a square
  painter.drawEllipse(valueRect);

  painter.drawImage(valueRect, backImage_);
}
}// namespace View::Components