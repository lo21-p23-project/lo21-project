//
// Created by Pierre Roussel on 5/10/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SwitchButton.h" resolved

#include "SwitchButton.h"
#include "ui_SwitchButton.h"

namespace View::Components {

static const int s_height = 20;
static const int s_innerMargin = 4;
static const int s_handledSize = s_height - s_innerMargin * 2;
static const int s_width = s_handledSize * 2 + s_innerMargin * 2;

SwitchButton::SwitchButton(QWidget *parent) : QWidget(parent), ui(new Ui::SwitchButton) {
  ui->setupUi(this);

  setSizePolicy({QSizePolicy::Fixed, QSizePolicy::Fixed});
  setFocusPolicy(Qt::TabFocus);
  setAttribute(Qt::WA_Hover);
}

SwitchButton::~SwitchButton() {
  delete ui;
}

void SwitchButton::setChecked(bool checked) {
  if (m_checked_ == checked) {
    return;
  }
  m_checked_ = checked;
  emit toggled(m_checked_);
  update();
}

bool SwitchButton::isChecked() const {
  return m_checked_;
}

void SwitchButton::toggle() {
  setChecked(!m_checked_);
}

QSize SwitchButton::sizeHint() const {
  return {s_width, s_height};
}

void SwitchButton::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  // Another advantage o QStyle: custom widgets can share code
  // with it (here just the color repository, but we could share more code
  // if needed)
  // With QSS, we can't use QSS to style our custom widget
  if (!isEnabled()) {
    painter.setPen(Style::dark());
    painter.setOpacity(0.5);
  } else if (m_mouseDown_) {// TODO: Not working...
    painter.setPen(Style::pressedOutlineColor());
  } else if (underMouse() || hasFocus()) {
    painter.setPen(Style::lightBlue());
  } else {
    painter.setPen(Style::dark());
  }

  if (m_checked_) {
    painter.setBrush(Style::lightBlue());
  } else {
    painter.setBrush(Style::backgroundColor());
  }

  const qreal radius = height() / 2.0;
  painter.drawRoundedRect(
      QRectF(rect()).adjusted(
          0.5, 0.5, -0.5, -0.5),
      radius, radius);

  // Now draw the handle
  QRect valueRect = rect().adjusted(
      s_innerMargin, s_innerMargin,
      -s_innerMargin, -s_innerMargin);
  valueRect.setWidth(valueRect.height());// Must be a square

  if (m_checked_) {
    valueRect.moveLeft(width() / 2);
    painter.setPen(Style::dark());
    painter.setBrush(Style::backgroundColorCard());
  } else {
    painter.setPen(Style::dark());
    painter.setBrush(Style::lightGray());
  }
  painter.drawEllipse(valueRect);
}

void SwitchButton::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    m_mouseDown_ = true;
  } else {
    event->ignore();
  }
}

void SwitchButton::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton && m_mouseDown_) {
    m_mouseDown_ = false;
    toggle();
    emit checked(m_checked_);
  } else {
    event->ignore();
  }
}

void SwitchButton::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Space) {
    toggle();
    emit checked(m_checked_);
  } else {
    event->ignore();
  }
}
}// namespace View::Components
