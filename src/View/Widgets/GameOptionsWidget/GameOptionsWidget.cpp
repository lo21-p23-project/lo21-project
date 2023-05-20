//
// Created by Pierre Roussel on 5/6/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameOptionsWidget.h" resolved

#include "GameOptionsWidget.h"
#include "ui_GameOptionsWidget.h"

namespace View::Widgets {

static const std::vector<std::string> SWITCH_SELECTOR_TITLES = {"1 round", "3 rounds", "5 rounds", "7 rounds"};

GameOptionsWidget::GameOptionsWidget(const GameVersion gameVersion, const enum WidgetsOptions widget, const int index, QWidget *parent) : gameVersion_(gameVersion), StackedChildWidget(widget, index, parent), ui(new Ui::GameOptionsWidget) {
  ui->setupUi(this);

  QWidget *mainWidget = new QWidget;
  QVBoxLayout *mainLayout = new QVBoxLayout;

  // Game version label
  QLabel *title = new QLabel(tr(gameVersionToString(gameVersion).c_str()));
  title->setAlignment(Qt::AlignCenter);
  QFont titleFont = title->font();
  titleFont.setPointSize(20);
  titleFont.setBold(true);
  title->setFont(titleFont);

  // Switch button
  QWidget *switchButtonsWidget = new QWidget;
  QGridLayout *switchButtonsLayout = new QGridLayout;

  QWidget *switchTacticModeWidget = new QWidget;
  QHBoxLayout *switchTacticModeLayout = new QHBoxLayout;
  QLabel *switchTacticModeLabel = new QLabel("Tactic Mode:");
  SwitchButton *switchButtonTacticMode = new SwitchButton;
  switchTacticModeLayout->addWidget(switchTacticModeLabel);
  switchTacticModeLayout->addWidget(switchButtonTacticMode);
  switchTacticModeLayout->setAlignment(Qt::AlignCenter);
  switchTacticModeWidget->setLayout(switchTacticModeLayout);

  QWidget *switchExpertModeWidget = new QWidget;
  QHBoxLayout *switchExpertModeLayout = new QHBoxLayout;
  QLabel *switchExpertModeLabel = new QLabel("Expert Mode:");
  SwitchButton *switchExpertMode = new SwitchButton;
  switchExpertModeLayout->addWidget(switchExpertModeLabel);
  switchExpertModeLayout->addWidget(switchExpertMode);
  switchExpertModeLayout->setAlignment(Qt::AlignCenter);
  switchExpertModeWidget->setLayout(switchExpertModeLayout);

  QWidget *switchAIModeWidget = new QWidget;
  QHBoxLayout *switchAIModeLayout = new QHBoxLayout;
  QLabel *switchAIModeLabel = new QLabel("AI Mode:");
  SwitchButton *switchButtonAIMode = new SwitchButton;
  switchAIModeLayout->addWidget(switchAIModeLabel);
  switchAIModeLayout->addWidget(switchButtonAIMode);
  switchAIModeLayout->setAlignment(Qt::AlignCenter);
  switchAIModeWidget->setLayout(switchAIModeLayout);

  // Add the widgets to the layout
  switchButtonsLayout->addWidget(switchTacticModeWidget, 0, 0, Qt::AlignCenter);
  switchButtonsLayout->addWidget(switchExpertModeWidget, 0, 1, Qt::AlignCenter);
  switchButtonsLayout->addWidget(switchAIModeWidget, 0, 2, Qt::AlignCenter);

  switchButtonsWidget->setLayout(switchButtonsLayout);

  // Connect the switch buttons
  connect(switchButtonTacticMode, &SwitchButton::toggled, this, &GameOptionsWidget::setTacticModeSlot);
  connect(switchExpertMode, &SwitchButton::toggled, this, &GameOptionsWidget::setExpertModeSlot);
  connect(switchButtonAIMode, &SwitchButton::toggled, this, &GameOptionsWidget::setAImodeSlot);

  // Switch selector
  SwitchSelector *switchSelector = new SwitchSelector(SWITCH_SELECTOR_TITLES, 0, this);
  connect(switchSelector, &SwitchSelector::selectedIndexChangedSignal, this, &GameOptionsWidget::setNbRoundsSlot);

  // Continue button
  Button *continueButton = new Button("Continue");
  connect(continueButton, &Button::clicked, [=, this]() {
    this->switchToNewWidget(WidgetsOptions::GAME);
  });

  // Set the layout to the main widget
  mainLayout->addWidget(title, 0, Qt::AlignVCenter);
  mainLayout->addWidget(switchButtonsWidget, 0, Qt::AlignVCenter);
  mainLayout->addWidget(switchSelector, 0, Qt::AlignVCenter);
  mainLayout->addWidget(continueButton, 0, Qt::AlignCenter);

  // Set the layout to the main widget
  mainWidget->setLayout(mainLayout);

  this->layout()->addWidget(mainWidget);
}

GameOptionsWidget::~GameOptionsWidget() {
  delete ui;
}

void GameOptionsWidget::setTacticModeSlot() {
  tacticMode_ = !tacticMode_;
}

void GameOptionsWidget::setExpertModeSlot() {
  expertMode_ = !expertMode_;
}

void GameOptionsWidget::setAImodeSlot() {
  aiMode_ = !aiMode_;
}

void GameOptionsWidget::setNbRoundsSlot(const int nbRounds) {
  switch (nbRounds) {
  case 3:
    nbRounds_ = 7;
    break;
  case 2:
    nbRounds_ = 5;
    break;
  case 1:
    nbRounds_ = 3;
    break;
  case 0:
  default:
    nbRounds_ = 1;
    break;
  }
}
}// namespace View::Widgets
