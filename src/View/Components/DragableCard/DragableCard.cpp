/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/19/2023
 * @copyright Copyright 2023 All rights reserved.
 */

#include "DragableCard.h"
#include "../../Style/Style.h"
#include "ui_DragableCard.h"

DragableCard::DragableCard(QWidget *parent) : QLabel(parent), ui(new Ui::DragableCard) {
  ui->setupUi(this);
  m_originalPosition = this->pos();
}

void DragableCard::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::LeftButton)
    m_dragStartPosition = event->pos();
}

void DragableCard::mouseReleaseEvent(QMouseEvent* event) {
  if (!(event->button() & Qt::LeftButton))
    return;

  if (!(event->pos() == m_originalPosition))
    this->move(m_originalPosition);

}

void DragableCard::mouseMoveEvent(QMouseEvent* event) {
  if (!(event->buttons() & Qt::LeftButton))
    return;
  if ((event->pos() - m_dragStartPosition).manhattanLength()
      < QApplication::startDragDistance())
    return;

  QPoint currentPosition = this->pos();

  QPoint diff = event->pos() - m_dragStartPosition;

  this->move(currentPosition + diff);
}

/**
 * Sets the new image to render onto the screen
 * @param imagePath
 */
void DragableCard::setImage(const QString& imagePath) {
  this->backImage_ = QImage(imagePath);
}

void DragableCard::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

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

  QPixmap pixmap = QPixmap::fromImage(backImage_);
  QPixmap scaledPixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

  painter.drawPixmap(0, 0, scaledPixmap);
}

DragableCard::~DragableCard() {
  delete ui;
}
