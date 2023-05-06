/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_EDITMENU_H
#define LO21_PROJECT_EDITMENU_H

#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui {
class EditMenu;
}
QT_END_NAMESPACE

class EditMenu : public QMenu {
  Q_OBJECT

public:
  explicit EditMenu(QString title = tr("&Edit"));

  ~EditMenu() override;

private:
  Ui::EditMenu *ui;
};

#endif//LO21_PROJECT_EDITMENU_H
