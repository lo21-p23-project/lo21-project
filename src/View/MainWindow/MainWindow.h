/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_MAINWINDOW_H
#define LO21_PROJECT_MAINWINDOW_H

#include "../MenuBar/MenuBar.h"
#include "../Widgets/HomeWidget/HomeWidget.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow() override;

private:
  Ui::MainWindow *ui;
};

#endif//LO21_PROJECT_MAINWINDOW_H
