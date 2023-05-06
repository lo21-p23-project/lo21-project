/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

// You may need to build the project (run Qt uic code generator) to get "ui_WorkInProgressWidget.h" resolved

#include "WorkInProgressWidget.h"
#include "ui_WorkInProgressWidget.h"

WorkInProgressWidget::WorkInProgressWidget(QWidget *parent) : QWidget(parent), ui(new Ui::WorkInProgressWidget) {
  ui->setupUi(this);

  this->setWindowTitle(tr("Work in Progress"));

  QHBoxLayout *layout = new QHBoxLayout;

  // Current directory is <app-directory>/cmake-build-debug
  QPixmap workInProgressImage("../assets/icons/work-in-progress_v3.png");
  QLabel *imageLabel = new QLabel;
  imageLabel->setPixmap(workInProgressImage);

  QLabel *label = new QLabel(tr("This feature is not yet implemented...\nWe are still working on it. Please come back later."));

  layout->addWidget(imageLabel, 0, Qt::AlignCenter);
  layout->addWidget(label, 0, Qt::AlignCenter);

  // Set the layout to the main widget
  this->setLayout(layout);
  this->setFixedSize(450, 150);
}

WorkInProgressWidget::~WorkInProgressWidget() {
  delete ui;
}
