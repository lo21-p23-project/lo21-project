
/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/19/2023
 * @copyright Copyright } 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_DRAGABLECARD_H
#define LO21_PROJECT_DRAGABLECARD_H

#include <QLabel>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QApplication>
#include <QPainter>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui {
class DragableCard;
}
QT_END_NAMESPACE

class DragableCard : public QLabel {
  Q_OBJECT

public:
  explicit DragableCard(QWidget *parent = nullptr);
  void setImage(const QString& imagePath);
  ~DragableCard() override;

protected:
  void mousePressEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void paintEvent(QPaintEvent *event) override;

private:
  QPoint m_originalPosition; /* this should be updated only when on a slot */
  QPoint m_dragStartPosition;
  Ui::DragableCard *ui;

  /* This is the image that is painted to the screen */
  QImage backImage_ = QImage("../assets/images/cards/card_test.png");
};

#endif//LO21_PROJECT_DRAGABLECARD_H
