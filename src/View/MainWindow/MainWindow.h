//
// Created by Pierre Roussel on 4/25/23.
//

#ifndef LO21_PROJECT_MAINWINDOW_H
#define LO21_PROJECT_MAINWINDOW_H

#include <QMainWindow>
#include "../Widgets/HomeWidget/HomeWidget.h"
#include "../MenuBar/MenuBar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow() override;

private:
  Ui::MainWindow *ui;
};


#endif //LO21_PROJECT_MAINWINDOW_H


