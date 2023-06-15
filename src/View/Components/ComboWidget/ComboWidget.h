//
// Created by Pierre Roussel on 6/6/23.
//

#ifndef LO21_PROJECT_COMBOWIDGET_H
#define LO21_PROJECT_COMBOWIDGET_H

#include "../../../Constants/Constants.h"
#include "../../Style/Style.h"
#include "../CardManager/CardManager.h"
#include "../CardSlot/CardSlot.h"
#include "../DragableCard/DragableCard.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class ComboWidget;
}
QT_END_NAMESPACE

namespace View::Components {

class ComboWidget : public QWidget {
  Q_OBJECT

public:
  explicit ComboWidget(CardManager *cardManager, QWidget *parent = nullptr);
  ~ComboWidget() override;

private:
  Ui::ComboWidget *ui;

  std::vector<CardSlot *> slots_;
};
}// namespace View::Components

#endif//LO21_PROJECT_COMBOWIDGET_H
