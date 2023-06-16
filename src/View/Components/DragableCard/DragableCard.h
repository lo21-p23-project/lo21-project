/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/19/2023
 * @copyright Copyright 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_DRAGABLECARD_H
#define LO21_PROJECT_DRAGABLECARD_H

#include "../CardManager/CardManager.h"
#include "../../../Model/Shotten/Cards/CardTypes/NormalCard.h"

#include <QApplication>
#include <QDrag>
#include <QLabel>
#include <QMimeData>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui {
class DragableCard;
}
QT_END_NAMESPACE

namespace View::Components {

class DragableCard : public QLabel {
  Q_OBJECT

public:
  explicit DragableCard(QWidget *parent = nullptr);
  void setImage(const QString &imagePath);
  void setCardManager(CardManager *manager);
  ~DragableCard() override;

protected:
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;

private:
  QPoint m_originalPosition; /* this should be updated only when on a slot */
  QPoint m_dragStartPosition;
  Ui::DragableCard *ui;

  /* This is the image that is painted to the screen */
  QImage backImage_ = QImage("../assets/images/cards/card_test.png");

  CardManager *cardManager_;
};
}// namespace View::Components

#endif//LO21_PROJECT_DRAGABLECARD_H
