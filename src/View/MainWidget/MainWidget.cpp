//
// Created by Pierre Roussel on 5/7/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWidget.h" resolved

#include "MainWidget.h"
#include "ui_MainWidget.h"

namespace View {

/**
 * @brief MainWidget::MainWidget
 * @details The main widget is the main widget of the application.
 * It contains the stacked widget and is rendered in the centralWidget of the MainWindow.
 * @param parent
 */
MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MainWidget) {
  ui->setupUi(this);

  QVBoxLayout *mainLayout = new QVBoxLayout;

  // Add the stacked widget to the main layout
  StackedWidget *stackedWidget = new StackedWidget(this);
  mainLayout->addWidget(stackedWidget);

  // Set the layout to the main widget
  this->setLayout(mainLayout);
}

MainWidget::~MainWidget() {
  delete ui;
}
}// namespace View
