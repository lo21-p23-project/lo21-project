//
// Created by Pierre Roussel on 5/9/23.
//

#ifndef LO21_PROJECT_STACKEDCHILDWIDGET_H
#define LO21_PROJECT_STACKEDCHILDWIDGET_H

#include "../Constants/Widgets.h"
#include "../Utils/WidgetsUtils.h"
#include "../Components/BackButton/BackButton.h"

#include <QVBoxLayout>
#include <QWidget>

#include <string>

// For debugging purposes
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class StackedChildWidget;
}
QT_END_NAMESPACE

class StackedChildWidget : public QWidget {
  Q_OBJECT

public:
  explicit StackedChildWidget(Widgets widget, int index, QWidget *parent = nullptr);
  ~StackedChildWidget() override;

public slots:
  void switchToNewWidget(Widgets widget, NavigationParams params = {});
  void navigateBack();

signals:
  void switchToNewWidgetSignal(Widgets widget, NavigationParams params = {});
  void navigateBackSignal(NavigationParams params = {});

private:
  Ui::StackedChildWidget *ui;
  const std::string widgetName;
  const int stackIndex;
};

#endif//LO21_PROJECT_STACKEDCHILDWIDGET_H
