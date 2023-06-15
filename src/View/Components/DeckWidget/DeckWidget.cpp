//
// Created by Pierre Roussel on 6/14/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DeckWidget.h" resolved

#include "DeckWidget.h"
#include "ui_DeckWidget.h"

namespace View::Components {

DeckWidget::DeckWidget(GameVersion gameVersion, QWidget *parent) : QWidget(parent), ui(new Ui::DeckWidget) {
  ui->setupUi(this);

  setAttribute(Qt::WA_Hover);
}

DeckWidget::~DeckWidget() {
  delete ui;
}

void DeckWidget::toggle() {
  std::cout << "DeckWidget - toggle" << std::endl;
  emit toggled();
}

void DeckWidget::paintEvent(QPaintEvent *event) {
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

void DeckWidget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    m_mouseDown_ = true;
  } else {
    event->ignore();
  }
}

void DeckWidget::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton && m_mouseDown_) {
    m_mouseDown_ = false;
    toggle();
  } else {
    event->ignore();
  }
}
}// namespace View::Components
