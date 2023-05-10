//
// Created by Pierre Roussel on 5/8/23.
//

#ifndef LO21_PROJECT_STACKEDWIDGET_H
#define LO21_PROJECT_STACKEDWIDGET_H

#include "../Constants/Widgets.h"
#include "../Utils/WidgetsUtils.h"
#include "../Widgets/GameOptionsWidget/GameOptionsWidget.h"
#include "../Widgets/HomeWidget/HomeWidget.h"

#include <QStackedWidget>

// For debugging purposes
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class StackedWidget;
}
QT_END_NAMESPACE

class StackedWidget : public QStackedWidget {
  Q_OBJECT

public:
  explicit StackedWidget(QWidget *parent = nullptr);
  ~StackedWidget() override;

public slots:
  void switchToNewWidget(Widgets widget, NavigationParams params = {});
  void navigateBack(NavigationParams params = {});

private:
  Ui::StackedWidget *ui;
};

#endif//LO21_PROJECT_STACKEDWIDGET_H
