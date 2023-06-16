/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/24/2023
 * @copyright Copyright 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_CARDSLOT_H
#define LO21_PROJECT_CARDSLOT_H

#include "../../Constants/CardSlotType.h"
#include "../../Style/Style.h"

#include <QHBoxLayout>
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
  explicit CardSlot(CardSlotType cardSlotType, QWidget *parent = nullptr);
  ~CardSlot() override;

  CardSlotType getCardSlotType() const { return cardSlotType_; };

  /* should we render the card slot hints ? */
  bool shouldRender = false;

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  Ui::CardSlot *ui;

  CardSlotType cardSlotType_;
};
}// namespace View::Components

#endif//LO21_PROJECT_CARDSLOT_H
