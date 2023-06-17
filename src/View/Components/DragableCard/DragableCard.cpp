/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/19/2023
 * @copyright Copyright 2023 All rights reserved.
 */

#include "DragableCard.h"
#include "../../Style/Style.h"
#include "ui_DragableCard.h"

namespace View::Components {

DragableCard::DragableCard(const QPoint originalPosition, const QSize originalSize, CardManager *cardManager, QWidget *parent) : m_originalPosition_(originalPosition), m_originalSize_(originalSize), cardManager_(cardManager), QWidget(parent), ui(new Ui::DragableCard) {
//  ui->setupUi(this);

  QHBoxLayout *mainLayout = new QHBoxLayout;
  this->setLayout(mainLayout);

  cout << "DragableCard::DragableCard: " << endl;
}

void DragableCard::mousePressEvent(QMouseEvent *event) {
  cout << "DragableCard::mousePressEvent: " << endl;
  if (event->button() == Qt::LeftButton) {
    m_dragStartPosition_ = event->pos();
  }
}

void DragableCard::setCardManager(CardManager *manager) {
  cardManager_ = manager;
}

void DragableCard::mouseReleaseEvent(QMouseEvent *event) {
  if (!(event->button() & Qt::LeftButton))
    return;

  CardSlot *slot = cardManager_->getCardSlotAt(mapToParent(event->pos()));
  if (slot != nullptr) {
    this->move(slot->pos());
    m_originalPosition_ = this->pos();
  } else {
    this->move(m_originalPosition_);
  }

  cardManager_->setRenderSlots(false);
}

void DragableCard::mouseMoveEvent(QMouseEvent *event) {
  if (!(event->buttons() & Qt::LeftButton))
    return;
  if ((event->pos() - m_dragStartPosition_).manhattanLength()
      < QApplication::startDragDistance())
    return;

  cardManager_->setRenderSlots(true);

  QPoint currentPosition = this->pos();

  QPoint diff = event->pos() - m_dragStartPosition_;

  this->move(currentPosition + diff);
}

/**
 * Sets the new image to render onto the screen
 * @param imagePath
 */
void DragableCard::setImage(const QString &imagePath) {
  this->backImage_ = QImage(imagePath);
}

void DragableCard::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

//  if (!isEnabled()) {
//    painter.setPen(Style::dark());
//    painter.setOpacity(0.5);
//  } else if (underMouse() || hasFocus()) {
//    painter.setPen(Style::lightBlue());
//    painter.setOpacity(0.8);
//  } else {
//    painter.setPen(Style::dark());
//  }

  painter.setBrush(Style::backgroundColorCard());
  painter.setPen(Style::dark());
  const qreal radius = 5.0;
  painter.drawRoundedRect(
      QRectF(m_originalPosition_, m_originalSize_),
      radius, radius);

//  QPixmap pixmap = QPixmap::fromImage(backImage_);
//  QPixmap scaledPixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//
//  painter.drawPixmap(0, 0, scaledPixmap);
}

DragableCard::~DragableCard() {
  delete ui;
}
}// namespace View::Components
