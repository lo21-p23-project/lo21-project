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

PlayerWidget::PlayerWidget(const NavigationParams& params, const WidgetsOptions widget, const int index, QWidget *parent) : StackedChildWidget(widget, index, parent), ui(new Ui::PlayerWidget) {
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

  // Player age input
  QWidget *playerAgeWidget = new QWidget;
  QHBoxLayout *playerAgeLayout = new QHBoxLayout;
  QLabel *playerAgeLabel = new QLabel("Date of Birth:");
  TextInput *playerAgeInput = new TextInput("dd-mm-yyyy");
  playerAgeLayout->addWidget(playerAgeLabel, Qt::AlignHCenter);
  playerAgeLayout->addWidget(playerAgeInput, Qt::AlignVCenter);
  playerAgeWidget->setLayout(playerAgeLayout);

  // Add Button
  Button *continueButton = new Button("Continue");

  // Add the widgets to the layout
  mainLayout->addWidget(title);
  mainLayout->addWidget(playerNameWidget);
  mainLayout->addWidget(playerAgeWidget);
  mainLayout->addWidget(continueButton);
  mainLayout->setAlignment(Qt::AlignVCenter);

  // Set the layout to the main widget
  mainWidget->setLayout(mainLayout);

  // Connect the continue button to the stacked widget
  connect(continueButton, &Button::clicked, [=, this]() {
    const std::string playerName = playerNameInput->text().toStdString();
    const std::string playerAge = playerAgeInput->text().toStdString();

    std::cout << "Player name: " << playerName << std::endl;
    std::cout << "Player age: " << playerAge << std::endl;

    // Regex to check if the player name is valid
    // The player name can only contain letters, numbers, dash and underscores
    const std::regex playerNameRegex("^[a-zA-Z0-9_-]{3,16}$");
    // Regex to check if the player age is valid
    // Separator can be either / or -
    // format: dd/mm/yyyy or dd-mm-yyyy
    const std::regex playerAgeRegex("^(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[012])-(19|20)\\d\\d$");

    bool validPlayerName = true;
    // Check if the player name is valid
    if (!std::regex_match(playerName, playerNameRegex)) {
      std::cout << "Invalid player name" << std::endl;
      validPlayerName = false;
    }
    bool validPlayerAge = true;
    // Check if the player age is valid
    if (!std::regex_match(playerAge, playerAgeRegex)) {
      std::cout << "Invalid player age" << std::endl;
      validPlayerAge = false;
    }

    if (!validPlayerName || !validPlayerAge) {
      return;
    }

    std::istringstream ss(playerAge);
    date::year_month_day ymd;
    date::sys_days parsedDate;
    ss >> date::parse("%d-%m-%Y", parsedDate);

    if (ss.fail()) {
      std::cout << "Failed to parse the date string.\n";

    } else {
      ymd = date::year_month_day{parsedDate};
      std::cout << "Parsed date: " << ymd << "\n";
    }

    if (!params.gameOptions->aiMode && params.playerNumber == 0) {
      std::shared_ptr<Player::Player> player = GameCreationController::createPlayer(playerName, "None", ymd);

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
        player = GameCreationController::createPlayer(playerName, "None", ymd);
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
