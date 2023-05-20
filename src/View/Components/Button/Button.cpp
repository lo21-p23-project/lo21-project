//
// Created by Pierre Roussel on 5/11/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Button.h" resolved

#include "Button.h"
#include "ui_Button.h"

namespace View::Components {

Button::Button(const std::string &title, const bool reversed, QWidget *parent) : title_(title.c_str()), reversed_(reversed), QPushButton(title.c_str(), parent), ui(new Ui::Button) {
  ui->setupUi(this);

  setAttribute(Qt::WA_Hover);
}

Button::~Button() {
  delete ui;
}

void Button::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  // Another advantage o QStyle: custom widgets can share code
  // with it (here just the color repository, but we could share more code
  // if needed)
  // With QSS, we can't use QSS to style our custom widget
  if (!isEnabled()) {
    painter.setPen(reversed_ ? Style::lightBlue() : Style::dark());
    painter.setOpacity(0.5);
  } else if (m_mouseDown_) {// TODO: Not working...
    painter.setPen(Style::pressedOutlineColor());
  } else if (underMouse() || hasFocus()) {
    painter.setPen(Style::lightBlue());
    painter.setOpacity(0.8);
  } else {
    painter.setPen(Style::dark());
  }

  painter.setBrush(reversed_ ? Style::backgroundColor() : Style::lightBlue());
  const qreal radius = height() / 2.0;
  painter.drawRoundedRect(
      QRectF(rect()).adjusted(
          0.5, 0.5, -0.5, -0.5),
      radius, radius);

  painter.setPen(Style::dark());
  painter.drawText(rect(), Qt::AlignCenter, title_);
}
}// namespace View::Components
