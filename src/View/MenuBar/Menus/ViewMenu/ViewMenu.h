/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_VIEWMENU_H
#define LO21_PROJECT_VIEWMENU_H

#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui {
class ViewMenu;
}
QT_END_NAMESPACE

class ViewMenu : public QMenu {
  Q_OBJECT

public:
  explicit ViewMenu(QString title = tr("&View"));

  ~ViewMenu() override;

private:
  Ui::ViewMenu *ui;
};

#endif//LO21_PROJECT_VIEWMENU_H
