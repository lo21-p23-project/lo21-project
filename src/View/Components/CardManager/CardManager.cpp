
/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/24/2023
 * @copyright Copyright } 2023 All rights reserved.
 */

#include "CardManager.h"

namespace View::Components {

CardManager::CardManager(QObject *parent)
    : QObject(parent),
      cardSlots() {
}

void CardManager::registerCardSlot(CardSlot *slot) {
  cardSlots.append(slot);
}

void CardManager::setRenderSlots(bool shouldRender) {
  for (auto slot : cardSlots) {
    slot->shouldRender = shouldRender;
    slot->update(); /* we need to rerender the widget */
  }
}

/**
 * Returns whether or not a given position is contained by a CardSlot from the current CardManager
 * @param pos
 * @return
 */
CardSlot *CardManager::getCardSlotAt(const QPoint &pos) {
  for (CardSlot *slot : cardSlots) {
    if (slot->geometry().contains(pos)) {
      return slot;
    }
  }
  return nullptr;
}
}// namespace View::Components