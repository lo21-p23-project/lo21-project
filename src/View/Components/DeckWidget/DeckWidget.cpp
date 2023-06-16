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

  std::cout << "DeckWidget - remainingCards: " << remainingCards_ << std::endl;

  setAttribute(Qt::WA_Hover);
}

DeckWidget::~DeckWidget() {
  delete ui;
}

shared_ptr<vector<shared_ptr<NormalCard>>> DeckWidget::drawNormalCards(const unsigned int numberOfCards) {
  shared_ptr<vector<shared_ptr<NormalCard>>> normalCards = make_shared<vector<shared_ptr<NormalCard>>>();
  for (int i = 0; i < numberOfCards; i++) {
    std::shared_ptr<NormalCard> normalCard = DeckController::drawNormalCard();
    normalCards->push_back(normalCard);
  }

  return normalCards;
}

void DeckWidget::toggle() {
  std::cout << "DeckWidget - toggle" << std::endl;

  if (remainingCards_ == 0) {
    return;
  }

  shared_ptr<NormalCard> normalCard = nullptr;
  shared_ptr<TacticCard> tacticCard = nullptr;

  switch (deckType_) {
  case DeckType::NORMAL:
    normalCard = DeckController::drawNormalCard();
    emit normalCardDrawn(normalCard);
    break;
  case DeckType::TACTIC:
    tacticCard = DeckController::drawTacticCard();
    emit tacticCardDrawn(tacticCard);
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