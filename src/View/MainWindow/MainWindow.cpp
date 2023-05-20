//
// Created by Pierre Roussel on 4/25/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"

namespace View {

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  MainWindow::setWindowTitle("Schotten-Totten");

  // Set the mainWidget as the central widget of the window
  MainWidget *mainWidget = new MainWidget(this);
  MainWindow::setCentralWidget(mainWidget);

  // Create a menu bar
  MenuBar *menuBar = new MenuBar;
  MainWindow::setMenuBar(menuBar);
}

MainWindow::~MainWindow() {
  delete ui;
}
}// namespace View
