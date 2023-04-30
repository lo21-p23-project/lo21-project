//
// Created by Pierre Roussel on 4/25/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  MainWindow::setWindowTitle("Schotten-Totten");

  // Set the mainWidget as the central widget of the window
  HomeWidget *homeWidget = new HomeWidget(this);
  MainWindow::setCentralWidget(homeWidget);

  // Test QMenuBar
  //  QAction *quitAction = new QAction("Quit");
  //  connect(quitAction,&QAction::triggered,[=](){
  //    QApplication::quit();
  //  });

  // Create a menu bar
  //  QMenuBar *menuBar = new QMenuBar;
  MenuBar *menuBar = new MenuBar();
  MainWindow::setMenuBar(menuBar);
}

MainWindow::~MainWindow() {
  delete ui;
}
