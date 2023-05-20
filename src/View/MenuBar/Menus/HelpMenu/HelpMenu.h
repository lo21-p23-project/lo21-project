//
// Created by Pierre Roussel on 4/30/23.
//

#ifndef LO21_PROJECT_HELPMENU_H
#define LO21_PROJECT_HELPMENU_H

#include "../../../../Constants/Constants.h"
#include "../../../Widgets/WorkInProgressWidget/WorkInProgressWidget.h"
#include <QMenu>

using namespace View::Widgets;

QT_BEGIN_NAMESPACE
namespace Ui {
class HelpMenu;
}
QT_END_NAMESPACE

namespace View::Menus {

class HelpMenu : public QMenu {
  Q_OBJECT

public:
  explicit HelpMenu(QString title = tr("&Help"), QWidget *parent = nullptr);

  ~HelpMenu() override;

private slots:

private:
  Ui::HelpMenu *ui;
  QWidget *parent;

  void openRules(GameVersion gameVersion = GameVersion::VERSION1);
};
}// namespace View::Menus

#endif//LO21_PROJECT_HELPMENU_H
