//
// Created by Pierre Roussel on 5/6/23.
//

#ifndef LO21_PROJECT_GAMEOPTIONSWIDGET_H
#define LO21_PROJECT_GAMEOPTIONSWIDGET_H

#include "../StackedChildWidget.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class GameOptionsWidget; }
QT_END_NAMESPACE

class GameOptionsWidget: public StackedChildWidget {
Q_OBJECT

public:
  explicit GameOptionsWidget(GameVersion gameVersion, Widgets widget, int index, QWidget *parent = nullptr);

  ~GameOptionsWidget() override;

private:
  Ui::GameOptionsWidget *ui;
};


#endif //LO21_PROJECT_GAMEOPTIONSWIDGET_H
