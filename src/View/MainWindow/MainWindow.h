//
// Created by Pierre Roussel on 4/25/23.
//

#ifndef LO21_PROJECT_MAINWINDOW_H
#define LO21_PROJECT_MAINWINDOW_H

#include "../MainWidget/MainWidget.h"
#include "../MenuBar/MenuBar.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace View {
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow() override;

private:
  Ui::MainWindow *ui;
};
}// namespace View

#endif//LO21_PROJECT_MAINWINDOW_H
