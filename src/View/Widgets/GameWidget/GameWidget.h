//
// Created by Pierre Roussel on 5/19/23.
//

#ifndef LO21_PROJECT_GAMEWIDGET_H
#define LO21_PROJECT_GAMEWIDGET_H

#include "../StackedChildWidget.h"
#include "../../Constants/Widgets.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class GameWidget;
}
QT_END_NAMESPACE

class GameWidget : public StackedChildWidget {
  Q_OBJECT

public:
  explicit GameWidget(Widgets widget, int index, QWidget *parent = nullptr);
  ~GameWidget() override;

private:
  Ui::GameWidget *ui;
};

#endif//LO21_PROJECT_GAMEWIDGET_H
