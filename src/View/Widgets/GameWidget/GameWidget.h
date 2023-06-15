//
// Created by Pierre Roussel on 5/19/23.
//

#ifndef LO21_PROJECT_GAMEWIDGET_H
#define LO21_PROJECT_GAMEWIDGET_H

#include "../../Components/CardManager/CardManager.h"
#include "../../Components/DeckWidget/DeckWidget.h"
#include "../../Components/Button/Button.h"
#include "../../Components/HandWidget/HandWidget.h"
#include "../../Components/BorderWidget/BorderWidget.h"
#include "../../Constants/WidgetsOptions.h"
#include "../StackedChildWidget.h"

#include <QWidget>
#include <QVBoxLayout>

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
  explicit GameWidget(const NavigationParams &params, WidgetsOptions widget, int index, QWidget *parent = nullptr);
  ~GameWidget() override;

private:
  Ui::GameWidget *ui;

  CardManager *cardManager;
};
}// namespace View::Widgets

#endif//LO21_PROJECT_GAMEWIDGET_H
