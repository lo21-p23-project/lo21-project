//
// Created by Pierre Roussel on 4/26/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_HomeWidget.h" resolved

#include "HomeWidget.h"
#include "ui_HomeWidget.h"


HomeWidget::HomeWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::HomeWidget) {
  ui->setupUi(this);
  QGridLayout *layout = new QGridLayout;

  // Create a label with "Schotten-Totten" text
  QLabel *label = new QLabel("Schotten-Totten");
  label->setAlignment(Qt::AlignCenter);
  // Set the font size to 32 and bold
  QFont font = label->font();
  font.setPointSize(32);
  font.setBold(true);
  label->setFont(font);

  // Create two buttons with "Version 1" and "Version 2" text
  QPushButton *button1 = new QPushButton("Version 1");
  QPushButton *button2 = new QPushButton("Version 2");


  // Add the label and the buttons to the layout
  layout->addWidget(label, 0, 0, 1, 2, Qt::AlignCenter);
  layout->addWidget(button1, 1, 0, 1, 1, Qt::AlignVCenter);
  layout->addWidget(button2, 1, 1, 1, 1, Qt::AlignVCenter);

  // Set the layout to the main widget
  this->setLayout(layout);
}

HomeWidget::~HomeWidget() {
  delete ui;
}
