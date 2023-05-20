//
// Created by Pierre Roussel on 4/30/23.
//

#ifndef LO21_PROJECT_VIEWMENU_H
#define LO21_PROJECT_VIEWMENU_H

#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui {
class ViewMenu;
}
QT_END_NAMESPACE

namespace View::Menus {

class ViewMenu : public QMenu {
  Q_OBJECT

public:
  explicit ViewMenu(QString title = tr("&View"));

  ~ViewMenu() override;

private:
  Ui::ViewMenu *ui;
};
}// namespace View::Menus

#endif//LO21_PROJECT_VIEWMENU_H
