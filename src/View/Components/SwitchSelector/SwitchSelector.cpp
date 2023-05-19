//
// Created by Pierre Roussel on 5/13/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SwitchSelector.h" resolved

#include "SwitchSelector.h"
#include "ui_SwitchSelector.h"

// For debugging purposes
#include <iostream>

SwitchSelector::SwitchSelector(const std::vector<std::string>& titles, const int initialIndex, QWidget *parent) : selectedIndex_(initialIndex), QWidget(parent), ui(new Ui::SwitchSelector) {
  ui->setupUi(this);

  QHBoxLayout *mainLayout = new QHBoxLayout(this);
  mainLayout->setContentsMargins(0, 0, 0, 0);
  mainLayout->setSpacing(0);

  for (int i = 0; i < titles.size(); ++i) {
    buttons_.push_back(new ButtonSelector(titles[i], i, initialIndex == i, this));
    mainLayout->addWidget(buttons_[i], 0, Qt::AlignVCenter);
    connect(buttons_[i], &ButtonSelector::clicked, [=, this]() {
      selectedIndexChanged(i);
    });
    connect(this, &SwitchSelector::selectedIndexChangedSignal, buttons_[i], &ButtonSelector::setSelected);
  }

  this->setLayout(mainLayout);
  this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

SwitchSelector::~SwitchSelector() {
  delete ui;
}

void SwitchSelector::selectedIndexChanged(int index) {
  selectedIndex_ = index;
  emit selectedIndexChangedSignal(index);
  update();
}

void SwitchSelector::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  painter.setPen(Style::backgroundColorCard());
  painter.setBrush(Style::backgroundColorCard());

  const qreal mainRadius = height() / 2.0;
  painter.drawRoundedRect(
      QRectF(
          rect()).adjusted(
              0.5, 0.5, -0.5, -0.5
              ),
      mainRadius, mainRadius);
}
