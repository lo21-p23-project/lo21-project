//
// Created by Pierre Roussel on 4/26/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_HomeWidget.h" resolved

#include "HomeWidget.h"
#include "ui_HomeWidget.h"

HomeWidget::HomeWidget(const Widgets widget, const int index, QWidget *parent) : StackedChildWidget(widget, index, parent), ui(new Ui::HomeWidget) {
  ui->setupUi(this);
  QWidget *mainWidget = new QWidget;
  QGridLayout *layout = new QGridLayout;

  // Create a label with "Schotten-Totten" text
  QLabel *label = new QLabel("Schotten-Totten");
  label->setAlignment(Qt::AlignCenter);
  // Set the font size to 32 and bold
  QFont font = label->font();
  font.setPointSize(32);
  font.setBold(true);
  label->setFont(font);

  // Create two buttons for the two game versions
  Button *originalButton = new Button("Original", true);
  NavigationParams originalParams;
  originalParams.gameVersion = GameVersion::VERSION1;
  connect(originalButton, &Button::clicked, [=, this]() {
    this->switchToNewWidget(Widgets::GAME_OPTIONS, originalParams);
  });

  Button *remasteredButton = new Button("Remastered", false);
  NavigationParams remasteredParams;
  remasteredParams.gameVersion = GameVersion::VERSION2;
  connect(remasteredButton, &Button::clicked, [=, this]() {
    this->switchToNewWidget(Widgets::GAME_OPTIONS, remasteredParams);
  });

  // Add the label and the buttons to the layout
  layout->addWidget(label, 0, 0, 1, 2, Qt::AlignCenter);
  layout->addWidget(originalButton, 1, 0, 1, 1, Qt::AlignVCenter);
  layout->addWidget(remasteredButton, 1, 1, 1, 1, Qt::AlignVCenter);

  // Set the layout to the main widget
  mainWidget->setLayout(layout);

  this->layout()->addWidget(mainWidget);
}

HomeWidget::~HomeWidget() {
  delete ui;
}
