//
// Created by Pierre Roussel on 5/19/23.
//

#ifndef LO21_PROJECT_GAMEWIDGET_H
#define LO21_PROJECT_GAMEWIDGET_H

#include "../../../Controller/GameController.h"
#include "../../Components/BorderWidget/BorderWidget.h"
#include "../../Components/Button/Button.h"
#include "../../Components/CardManager/CardManager.h"
#include "../../Components/DeckWidget/DeckWidget.h"
#include "../../Components/HandWidget/HandWidget.h"
#include "../../Constants/CardSlotType.h"
#include "../../Constants/WidgetsOptions.h"
#include "../StackedChildWidget.h"

#include <QVBoxLayout>
#include <QWidget>

using namespace View::Components;

QT_BEGIN_NAMESPACE
namespace Ui {
class GameWidget;
}
QT_END_NAMESPACE

namespace View::Widgets {

class GameWidget : public StackedChildWidget {
  Q_OBJECT

public:
  explicit GameWidget(WidgetsOptions widget, int index, QWidget *parent = nullptr);
  ~GameWidget() override;

signals:
  void requestInitializePlayersHandsSignals(ModeOptions mode = ModeOptions::NORMAL);

private:
  Ui::GameWidget *ui;

  CardManager *cardManager_;
  HandWidget *opponentHandWidget_;
  BorderWidget *borderWidget_;
  HandWidget *playerHandWidget_;
  QLabel *playerNameLabel_;
};
}// namespace View::Widgets

#endif//LO21_PROJECT_GAMEWIDGET_H
