//
// Created by Pierre Roussel on 6/1/23.
//

#ifndef LO21_PROJECT_HANDWIDGET_H
#define LO21_PROJECT_HANDWIDGET_H

#include "../../../Constants/Constants.h"
#include "../../Style/Style.h"
#include "../CardManager/CardManager.h"
#include "../CardSlot/CardSlot.h"
#include "../DragableCard/DragableCard.h"

#include <vector>

#include <QGridLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class HandWidget;
}
QT_END_NAMESPACE

namespace View::Components {

class HandWidget : public QWidget {
  Q_OBJECT

public:
  explicit HandWidget(CardManager *cardManager, GameVersion gameVersion = GameVersion::VERSION1, QWidget *parent = nullptr);
  ~HandWidget() override;

private:
  Ui::HandWidget *ui;

  std::vector<CardSlot *> slots_;
};
}// namespace View::Components

#endif//LO21_PROJECT_HANDWIDGET_H
