//
// Created by Pierre Roussel on 5/6/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameOptionsWidget.h" resolved

#include "GameOptionsWidget.h"
#include "ui_GameOptionsWidget.h"

GameOptionsWidget::GameOptionsWidget(const GameVersion gameVersion, const Widgets widget, const int index, QWidget *parent): StackedChildWidget(widget, index, parent), ui(new Ui::GameOptionsWidget) {
  ui->setupUi(this);

  QWidget *mainWidget = new QWidget;
  QVBoxLayout *mainLayout = new QVBoxLayout;

  QLabel *title = new QLabel(tr((gameVersionToString(gameVersion) + ": Set up your game option").c_str()));
  title->setAlignment(Qt::AlignCenter);
  QFont titleFont = title->font();
  titleFont.setPointSize(18);
  titleFont.setBold(true);
  title->setFont(titleFont);

  // Set the layout to the main widget
  mainLayout->addWidget(title, 0, Qt::AlignCenter);

  // Set the layout to the main widget
  mainWidget->setLayout(mainLayout);

  this->layout()->addWidget(mainWidget);
}

GameOptionsWidget::~GameOptionsWidget() {
  delete ui;
}
