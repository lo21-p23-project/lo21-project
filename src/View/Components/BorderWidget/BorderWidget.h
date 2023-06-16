//
// Created by Pierre Roussel on 6/6/23.
//

#ifndef LO21_PROJECT_BORDERWIDGET_H
#define LO21_PROJECT_BORDERWIDGET_H

#include "../../../Constants/Constants.h"
#include "../../../Controller/GameController.h"
#include "../../Constants/CardSlotType.h"
#include "../../Style/Style.h"
#include "../CardManager/CardManager.h"
#include "../CardSlot/CardSlot.h"
#include "../ComboWidget/ComboWidget.h"
#include "../DragableCard/DragableCard.h"

#include <QWidget>

using namespace Controller;

QT_BEGIN_NAMESPACE
namespace Ui {
class BorderWidget;
}
QT_END_NAMESPACE

namespace View::Components {

class BorderWidget : public QWidget {
  Q_OBJECT

public:
  explicit BorderWidget(CardManager *cardManager, QWidget *parent = nullptr);
  ~BorderWidget() override;

private:
  Ui::BorderWidget *ui;

  std::vector<CardSlot *> slots_;
};
}// namespace View::Components

#endif//LO21_PROJECT_BORDERWIDGET_H
