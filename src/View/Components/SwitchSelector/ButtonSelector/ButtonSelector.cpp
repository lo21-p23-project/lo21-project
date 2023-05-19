//
// Created by Pierre Roussel on 5/14/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ButtonSelector.h" resolved

#include "ButtonSelector.h"
#include "ui_ButtonSelector.h"

#include <QHBoxLayout>
#include <QPainter>

// For debugging purposes
#include <iostream>

ButtonSelector::ButtonSelector(const std::string &title, const int index, const bool selected, QWidget *parent) : QPushButton(parent), title_(title.c_str()), index_(index), selected_(selected), ui(new Ui::ButtonSelector) {
  ui->setupUi(this);

  QHBoxLayout *mainLayout = new QHBoxLayout(this);
  setAttribute(Qt::WA_Hover);
  mainLayout->setContentsMargins(100, 100, 100, 100);
  this->setLayout(mainLayout);
  this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

ButtonSelector::~ButtonSelector() {
  delete ui;
}

void ButtonSelector::setSelected(int index) {
  selected_ = index == index_;
}

void ButtonSelector::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  if (selected_) {
    painter.setBrush(Style::lightBlue());
  } else {
    painter.setPen(Qt::NoPen);
    painter.setBrush(Style::backgroundColorCard());
  }

  if (underMouse() || hasFocus()) {
    painter.setPen(Style::lightBlue());
    painter.setOpacity(0.8);
  }

  const qreal mainRadius = height() / 2.0;
  painter.drawRoundedRect(
      QRectF(
          rect())
          .adjusted(
              0.5, 0.5, -0.5, -0.5),
      mainRadius, mainRadius);

  painter.setPen(Style::dark());
  painter.drawText(rect(), Qt::AlignCenter, title_);
}
