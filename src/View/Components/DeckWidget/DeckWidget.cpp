//
// Created by Pierre Roussel on 6/14/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DeckWidget.h" resolved

#include "DeckWidget.h"
#include "ui_DeckWidget.h"

using namespace std;

namespace View::Components {

DeckWidget::DeckWidget(DeckType deckType, QWidget *parent) : deckType_(deckType), QWidget(parent), ui(new Ui::DeckWidget) {
  ui->setupUi(this);

  const GameVersion gameVersion = GameplayController::getGameOption()->version;

  DeckController::createDeck(gameVersion, deckType_);
  remainingCards_ = DeckController::getRemainingCards(deckType_);

  std::cout << "DeckWidget:init - remainingCards: " << remainingCards_ << std::endl;

  setAttribute(Qt::WA_Hover);
}

DeckWidget::~DeckWidget() {
  delete ui;
}

/**
 * @brief DeckWidget::drawNormalCards
 * @details Draws a number of cards from the deck and returns them.
 * @param numberOfCards
 * @return shared_ptr<vector<shared_ptr<NormalCard>>>
 */
shared_ptr<vector<shared_ptr<NormalCard>>> DeckWidget::drawNormalCards(const unsigned int numberOfCards) {
  shared_ptr<vector<shared_ptr<NormalCard>>> normalCards = make_shared<vector<shared_ptr<NormalCard>>>();
  for (int i = 0; i < numberOfCards; i++) {
    std::shared_ptr<NormalCard> normalCard = DeckController::drawNormalCard();
    normalCards->push_back(normalCard);
    remainingCards_--;
  }

  return normalCards;
}

/**
 * @brief DeckWidget::toggle
 * @details Draws a card from the deck when pressed and emits a signal with the card.
 *          If the deck is empty, nothing happens.
 * @return void
 */
void DeckWidget::toggle() {
  std::cout << "DeckWidget - toggle" << std::endl;

  if (remainingCards_ == 0) {
    return;
  }

  // TODO: Waiting for getPlayerTurn() to be implemented
  // emit checkPlayerCanReceiveCard(
  //   GameplayController::getPlayerTurn()->getUsername()
  //   );
  emit checkPlayerCanReceiveCardSignal(
    "col-roussel"
  );
}

void DeckWidget::canPlayerReceiveCard(bool canReceive) {
  if (!canReceive) {
    cout << "DeckWidget - canPlayerReceiveCard - player cannot receive card" << endl;
    return;
  }

  shared_ptr<NormalCard> normalCard = nullptr;
  shared_ptr<TacticCard> tacticCard = nullptr;

  switch (deckType_) {
  case DeckType::NORMAL:
    normalCard = DeckController::drawNormalCard();
    // TODO: Waiting for getPlayerTurn() to be implemented
    // emit normalCardDrawn(
    //     normalCard,
    //     GameplayController::getPlayerTurn()->getUsername()
    //     );
    emit normalCardDrawn(
        normalCard,
        "col-roussel"
    );
    break;
  case DeckType::TACTIC:
    tacticCard = DeckController::drawTacticCard();
    // TODO: Waiting for getPlayerTurn() to be implemented
    // emit tacticCardDrawn(
    //     tacticCard,
    //     GameplayController::getPlayerTurn()->getUsername()
    //     );
    emit tacticCardDrawn(
        tacticCard,
        "col-roussel"
    );
    break;
  case DeckType::DISCARD:
  default:
    break;
  }
  remainingCards_--;
  std::cout << "DeckWidget - remainingCards: " << remainingCards_ << std::endl;
  update();
}

void DeckWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  //  if (!shouldRender) { /* draw transparent rectangle instead of the black lines */
  //    return;
  //  }

  const qreal radius = 5.0;
  painter.setPen(Style::dark());
  if (remainingCards_ != 0) {
    painter.setBrush(Style::backgroundColorCard());
  }
  painter.drawRoundedRect(
      QRectF(rect()).adjusted(
          0.5, 0.5, -0.5, -0.5),
      radius, radius);
}

void DeckWidget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    m_mouseDown_ = true;
  } else {
    event->ignore();
  }
}

void DeckWidget::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton && m_mouseDown_) {
    m_mouseDown_ = false;
    toggle();
  } else {
    event->ignore();
  }
}

/**
 * @brief DeckWidget::requestInitializePlayersHands
 * @details Slot listening for requestInitializePlayersHandsSignal from GameWidget
 *          to initialize players' hands. It emits normalCardDrawnForInitilization
 *          signals to HandWidget to initialize players' hands.
 * @param mode
 * @return void
 */
void DeckWidget::requestInitializePlayersHands(ModeOptions mode) {
  std::cout << "DeckWidget - requestInitializePlayersHands" << std::endl;
  const unsigned int numberOfCardsDrawn = mode == ModeOptions::TACTIC ? 7 : 6;
  auto players = GameplayController::getPlayers();
  std::pair<std::string, std::string> playerNames;
  playerNames.first = players.first->getUsername();
  playerNames.second = players.second->getUsername();

  emit normalCardDrawnForInitilization(
      drawNormalCards(numberOfCardsDrawn),
      playerNames.first
      );
  emit normalCardDrawnForInitilization(
      drawNormalCards(numberOfCardsDrawn),
      playerNames.second
      );
}
}// namespace View::Components