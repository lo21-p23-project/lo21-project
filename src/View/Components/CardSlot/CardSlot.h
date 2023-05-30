/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/24/2023
 * @copyright Copyright 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_CARDSLOT_H
#define LO21_PROJECT_CARDSLOT_H

#include <QPainter>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class CardSlot;
}
QT_END_NAMESPACE

namespace View::Components {

class CardSlot : public QWidget {
  Q_OBJECT

public:
  explicit CardSlot(QWidget *parent = nullptr);
  ~CardSlot() override;

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  Ui::CardSlot *ui;
};
}// namespace View::Components

#endif//LO21_PROJECT_CARDSLOT_H
