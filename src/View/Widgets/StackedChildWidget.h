//
// Created by Pierre Roussel on 5/9/23.
//

#ifndef LO21_PROJECT_STACKEDCHILDWIDGET_H
#define LO21_PROJECT_STACKEDCHILDWIDGET_H

#include "../Components/BackButton/BackButton.h"
#include "../Constants/WidgetsOptions.h"
#include "../Utils/WidgetsUtils.h"

#include <QVBoxLayout>
#include <QWidget>

#include <string>

// For debugging purposes
#include <iostream>

using namespace View::Utils;
using namespace View::Constants;
using namespace View::Components;

QT_BEGIN_NAMESPACE
namespace Ui {
class StackedChildWidget;
}
QT_END_NAMESPACE

namespace View::Widgets {
class StackedChildWidget : public QWidget {
  Q_OBJECT

public:
  explicit StackedChildWidget(WidgetsOptions widget, int index, QWidget *parent = nullptr);
  ~StackedChildWidget() override;

public slots:
  void switchToNewWidget(WidgetsOptions widget, NavigationParams params = {});
  void navigateBack();

signals:
  void switchToNewWidgetSignal(WidgetsOptions widget, NavigationParams params = {});
  void navigateBackSignal(NavigationParams params = {});

private:
  Ui::StackedChildWidget *ui;
  const std::string widgetName;
  const int stackIndex;
};
}// namespace View::Widgets

#endif//LO21_PROJECT_STACKEDCHILDWIDGET_H
