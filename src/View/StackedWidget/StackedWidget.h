//
// Created by Pierre Roussel on 5/8/23.
//

#ifndef LO21_PROJECT_STACKEDWIDGET_H
#define LO21_PROJECT_STACKEDWIDGET_H

#include "../Constants/WidgetsOptions.h"
#include "../Utils/WidgetsUtils.h"
#include "../Widgets/GameOptionsWidget/GameOptionsWidget.h"
#include "../Widgets/GameWidget/GameWidget.h"
#include "../Widgets/HomeWidget/HomeWidget.h"
#include "../Widgets/PlayerWidget/PlayerWidget.h"

#include <QStackedWidget>

// For debugging purposes
#include <iostream>

using namespace View::Utils;
using namespace View::Constants;
using namespace View::Widgets;

QT_BEGIN_NAMESPACE
namespace Ui {
class StackedWidget;
}
QT_END_NAMESPACE

namespace View {

class StackedWidget : public QStackedWidget {
  Q_OBJECT

public:
  explicit StackedWidget(QWidget *parent = nullptr);
  ~StackedWidget() override;

public slots:
  void switchToNewWidget(WidgetsOptions widget, NavigationParams params = {});
  void navigateBack(NavigationParams params = {});

private:
  Ui::StackedWidget *ui;
};
}// namespace View

#endif//LO21_PROJECT_STACKEDWIDGET_H
