//
// Created by Pierre Roussel on 5/8/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StackedWidget.h" resolved

#include "StackedWidget.h"
#include "ui_StackedWidget.h"

using namespace View::Constants;

namespace View {

StackedWidget::StackedWidget(QWidget *parent) : QStackedWidget(parent), ui(new Ui::StackedWidget) {
  ui->setupUi(this);

//  Uncomment this before merging
//  HomeWidget *homeWidget = new HomeWidget(WidgetsOptions::HOME, 0);
//  this->addWidget(homeWidget);

  // Remove this before merging
  GameWidget *homeWidget = new GameWidget({}, WidgetsOptions::GAME, 0);
  this->addWidget(homeWidget);

  // Related to the navigation between the widgets
  // HomeWidget
  connect(homeWidget, &::HomeWidget::switchToNewWidgetSignal, this, &StackedWidget::switchToNewWidget);
}

StackedWidget::~StackedWidget() {
  delete ui;
}

void StackedWidget::switchToNewWidget(WidgetsOptions widget, NavigationParams params) {
  const int newStackIndex = this->currentIndex() + 1;

  switch (widget) {
  case WidgetsOptions::GAME: {
    std::cout << "StackedWidget - Switching to " << widgetToString(WidgetsOptions::GAME) << std::endl;

    GameWidget *gameWidget = new GameWidget({}, WidgetsOptions::GAME, newStackIndex);
    this->addWidget(gameWidget);
    // GameWidget
    connect(gameWidget, &::GameWidget::switchToNewWidgetSignal, this, &StackedWidget::switchToNewWidget);
    connect(gameWidget, &::GameWidget::navigateBackSignal, this, &StackedWidget::navigateBack);

    this->setCurrentIndex(newStackIndex);
    break;
  }
  case WidgetsOptions::PLAYER: {
    std::cout << "StackedWidget - Switching to " << widgetToString(WidgetsOptions::PLAYER) << std::endl;

    PlayerWidget *playerWidget = new PlayerWidget(params, WidgetsOptions::PLAYER, newStackIndex);
    this->addWidget(playerWidget);
    // PlayerWidget
    connect(playerWidget, &::PlayerWidget::switchToNewWidgetSignal, this, &StackedWidget::switchToNewWidget);
    connect(playerWidget, &::PlayerWidget::navigateBackSignal, this, &StackedWidget::navigateBack);

    this->setCurrentIndex(newStackIndex);
    break;
  }
  case WidgetsOptions::GAME_OPTIONS: {
    std::cout << "StackedWidget - Switching to " << widgetToString(WidgetsOptions::GAME_OPTIONS) << std::endl;
    GameVersion gameVersion = params.gameVersion;

    GameOptionsWidget *gameOptionsWidget = new GameOptionsWidget(gameVersion, WidgetsOptions::GAME_OPTIONS, newStackIndex);
    this->addWidget(gameOptionsWidget);
    // GameOptionsWidget
    connect(gameOptionsWidget, &::GameOptionsWidget::switchToNewWidgetSignal, this, &StackedWidget::switchToNewWidget);
    connect(gameOptionsWidget, &::GameOptionsWidget::navigateBackSignal, this, &StackedWidget::navigateBack);

    this->setCurrentIndex(newStackIndex);
    break;
  }
  case WidgetsOptions::HOME:
  default:
    std::cout << "StackedWidget - Switching to " << widgetToString(WidgetsOptions::HOME) << std::endl;
    this->setCurrentIndex(0);
  }
}

void StackedWidget::navigateBack(NavigationParams params) {
  std::cout << "navigateBack" << std::endl;
  const int currentIndex = this->currentIndex();
  if (currentIndex == 0) {
    std::cout << "StackedWidget - Cannot navigate back - Current Widget: " << widgetToString(WidgetsOptions::HOME) << std::endl;
    return;
  }
  this->setCurrentIndex(currentIndex - 1);
  auto widgetToDelete = this->widget(currentIndex);
  this->removeWidget(widgetToDelete);
  delete widgetToDelete;
}
}// namespace View
