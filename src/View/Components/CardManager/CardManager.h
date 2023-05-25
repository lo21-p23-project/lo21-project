
/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/24/2023
 * @copyright Copyright } 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_CARDMANAGER_H
#define LO21_PROJECT_CARDMANAGER_H

#include <QObject>
#include "../CardSlot/CardSlot.h"

class CardManager : public QObject {
  Q_OBJECT

public:
  explicit CardManager(QObject *parent = nullptr);
  void registerCardSlot(CardSlot *slot);
  CardSlot* getCardSlotAt(const QPoint& pos);

private:
  QList<CardSlot*> cardSlots;
};

#endif//LO21_PROJECT_CARDMANAGER_H
