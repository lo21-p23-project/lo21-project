//
// Created by Pierre Roussel on 5/8/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StackedWidget.h" resolved

#include "StackedWidget.h"
#include "ui_StackedWidget.h"

StackedWidget::StackedWidget(QWidget *parent) : QStackedWidget(parent), ui(new Ui::StackedWidget) {
  ui->setupUi(this);

  HomeWidget *homeWidget = new HomeWidget(Widgets::HOME, 0);
  this->addWidget(homeWidget);

  // Related to the navigation between the widgets
  // HomeWidget
  connect(homeWidget, &::HomeWidget::switchToNewWidgetSignal, this, &StackedWidget::switchToNewWidget);
}

StackedWidget::~StackedWidget() {
  delete ui;
}

void StackedWidget::switchToNewWidget(Widgets widget, NavigationParams params) {
  const int newStackIndex = this->currentIndex() + 1;

  switch (widget) {
  case Widgets::GAME: {
    std::cout << "StackedWidget - Switching to " << widgetToString(Widgets::GAME) << std::endl;

    GameWidget *gameWidget = new GameWidget(Widgets::GAME, newStackIndex);
    this->addWidget(gameWidget);
    // GameWidget
    connect(gameWidget, &::GameWidget::switchToNewWidgetSignal, this, &StackedWidget::switchToNewWidget);
    connect(gameWidget, &::GameWidget::navigateBackSignal, this, &StackedWidget::navigateBack);

    this->setCurrentIndex(newStackIndex);
    break;
  }
  case Widgets::GAME_OPTIONS: {
    std::cout << "StackedWidget - Switching to " << widgetToString(Widgets::GAME_OPTIONS) << std::endl;
    GameVersion gameVersion = params.gameVersion;

    GameOptionsWidget *gameOptionsWidget = new GameOptionsWidget(gameVersion, Widgets::GAME_OPTIONS, newStackIndex);
    this->addWidget(gameOptionsWidget);
    // GameOptionsWidget
    connect(gameOptionsWidget, &::GameOptionsWidget::switchToNewWidgetSignal, this, &StackedWidget::switchToNewWidget);
    connect(gameOptionsWidget, &::GameOptionsWidget::navigateBackSignal, this, &StackedWidget::navigateBack);

    this->setCurrentIndex(newStackIndex);
    break;
  }
  case Widgets::HOME:
  default:
    std::cout << "StackedWidget - Switching to " << widgetToString(Widgets::HOME) << std::endl;
    this->setCurrentIndex(0);
  }
}

void StackedWidget::navigateBack(NavigationParams params) {
  std::cout << "navigateBack" << std::endl;
  const int currentIndex = this->currentIndex();
  if (currentIndex == 0) {
    std::cout << "StackedWidget - Cannot navigate back - Current Widget: " << widgetToString(Widgets::HOME) << std::endl;
    return;
  }
  this->setCurrentIndex(currentIndex - 1);
  auto widgetToDelete = this->widget(currentIndex);
  this->removeWidget(widgetToDelete);
  delete widgetToDelete;
}
