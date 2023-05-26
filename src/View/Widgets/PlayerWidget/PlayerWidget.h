//
// Created by Pierre Roussel on 5/20/23.
//

#ifndef LO21_PROJECT_PLAYERWIDGET_H
#define LO21_PROJECT_PLAYERWIDGET_H

#include "../../Components/Button/Button.h"
#include "../../Components/TextInput/TextInput.h"
#include "../StackedChildWidget.h"

#include "../../Utils/WidgetsUtils.h"

#include "../../../Controller/GameCreationController.h"

#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

#include <date/date.h>
#include <regex>

using namespace View::Utils;
using namespace View::Components;
using namespace View::Constants;
using namespace Controller;

QT_BEGIN_NAMESPACE
namespace Ui {
class PlayerWidget;
}
QT_END_NAMESPACE

namespace View::Widgets {

class PlayerWidget : public StackedChildWidget {
  Q_OBJECT

public:
  explicit PlayerWidget(const NavigationParams &params, WidgetsOptions widget, int index, QWidget *parent = nullptr);
  ~PlayerWidget() override;

private:
  Ui::PlayerWidget *ui;
};
}// namespace View::Widgets

#endif//LO21_PROJECT_PLAYERWIDGET_H
