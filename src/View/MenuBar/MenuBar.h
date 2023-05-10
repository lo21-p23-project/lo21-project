//
// Created by Pierre Roussel on 4/30/23.
//

#ifndef LO21_PROJECT_MENUBAR_H
#define LO21_PROJECT_MENUBAR_H

#include "Menus/EditMenu/EditMenu.h"
#include "Menus/FileMenu/FileMenu.h"
#include "Menus/HelpMenu/HelpMenu.h"
#include "Menus/ViewMenu/ViewMenu.h"
#include <QMenuBar>

QT_BEGIN_NAMESPACE
namespace Ui {
class MenuBar;
}
QT_END_NAMESPACE

class MenuBar : public QMenuBar {
  Q_OBJECT

public:
  explicit MenuBar(QWidget *parent = nullptr);

  ~MenuBar() override;

private:
  Ui::MenuBar *ui;
};

#endif//LO21_PROJECT_MENUBAR_H
