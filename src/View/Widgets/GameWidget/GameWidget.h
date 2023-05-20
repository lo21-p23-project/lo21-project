//
// Created by Pierre Roussel on 5/19/23.
//

#ifndef LO21_PROJECT_GAMEWIDGET_H
#define LO21_PROJECT_GAMEWIDGET_H

#include "../../Constants/WidgetsOptions.h"
#include "../StackedChildWidget.h"

#include <QWidget>

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

private:
  Ui::GameWidget *ui;
};
}// namespace View::Widgets

#endif//LO21_PROJECT_GAMEWIDGET_H
