//
// Created by Pierre Roussel on 4/30/23.
//

#ifndef LO21_PROJECT_EDITMENU_H
#define LO21_PROJECT_EDITMENU_H

#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui {
class EditMenu;
}
QT_END_NAMESPACE

namespace View::Menus {

class EditMenu : public QMenu {
  Q_OBJECT

public:
  explicit EditMenu(QString title = tr("&Edit"));

  ~EditMenu() override;

private:
  Ui::EditMenu *ui;
};
}// namespace View::Menus

#endif//LO21_PROJECT_EDITMENU_H
