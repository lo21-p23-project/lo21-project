//
// Created by Pierre Roussel on 5/20/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PlayerWidget.h" resolved

#include "PlayerWidget.h"
#include "ui_PlayerWidget.h"

// For debugging purposes
#include <iostream>
#include <memory>
#include <utility>

namespace View::Widgets {

PlayerWidget::PlayerWidget(const NavigationParams &params, const WidgetsOptions widget, const int index, QWidget *parent) : StackedChildWidget(widget, index, parent), ui(new Ui::PlayerWidget) {
  ui->setupUi(this);

  QWidget *mainWidget = new QWidget;
  QVBoxLayout *mainLayout = new QVBoxLayout;

  // Player name label
  QLabel *title = new QLabel(tr((params.playerNumber == 0 ? "First Player" : "Second Player")));
  title->setAlignment(Qt::AlignCenter);
  title->setFont(Style::titleFont(title));

  // Player name input
  QWidget *playerNameWidget = new QWidget;
  QHBoxLayout *playerNameLayout = new QHBoxLayout;
  QLabel *playerNameLabel = new QLabel("Username:");
  TextInput *playerNameInput = new TextInput("username");
  playerNameLayout->addWidget(playerNameLabel, Qt::AlignHCenter);
  playerNameLayout->addWidget(playerNameInput, Qt::AlignVCenter);
  playerNameWidget->setLayout(playerNameLayout);

  // Add Button
  Button *continueButton = new Button("Continue");

  // Add the widgets to the layout
  mainLayout->addWidget(title);
  mainLayout->addWidget(playerNameWidget);
  mainLayout->addWidget(continueButton);
  mainLayout->setAlignment(Qt::AlignVCenter);

  // Set the layout to the main widget
  mainWidget->setLayout(mainLayout);

  // Connect the continue button to the stacked widget
  connect(continueButton, &Button::clicked, [=, this]() {
    const std::string playerName = playerNameInput->text().toStdString();

    std::cout << "Player name: " << playerName << std::endl;

    // Regex to check if the player name is valid
    // The player name can only contain letters, numbers, dash and underscores
    const std::regex playerNameRegex("^[a-zA-Z0-9_-]{3,16}$");

    bool validPlayerName = true;
    // Check if the player name is valid
    if (!std::regex_match(playerName, playerNameRegex)) {
      std::cout << "Invalid player name" << std::endl;
      validPlayerName = false;
    }

    if (!validPlayerName) {
      return;
    }

    if (!params.gameOptions->aiMode && params.playerNumber == 0) {
      std::shared_ptr<Player::Player> player = GameCreationController::createPlayer(playerName, "None");

      NavigationParams newParams;
      newParams.gameVersion = params.gameVersion;
      newParams.gameOptions = params.gameOptions;
      newParams.player = player;
      newParams.playerNumber = 1;
      this->switchToNewWidget(WidgetsOptions::PLAYER, newParams);
    } else {
      std::shared_ptr<Player::Player> player;

      if (params.gameOptions->aiMode) {
        // TODO: Implement AI mode
        std::cout << "AI Mode not implemented yet" << std::endl;
        return;
      } else {
        player = GameCreationController::createPlayer(playerName, "None");
      }

      std::pair<std::shared_ptr<Player::Player>, std::shared_ptr<Player::Player>> players;
      if (params.playerNumber == 0) {
        players = std::make_pair(player, params.player);
      } else {
        players = std::make_pair(params.player, player);
      }

      Game *game = GameCreationController::createGame(params.gameOptions, players, std::shared_ptr<Board::Board>());
      NavigationParams newParams;
      newParams.game = game;

      this->switchToNewWidget(WidgetsOptions::GAME, newParams);
    }
  });

  // Set the main widget to the stacked widget
  this->layout()->addWidget(mainWidget);
}

PlayerWidget::~PlayerWidget() {
  delete ui;
}
}// namespace View::Widgets
