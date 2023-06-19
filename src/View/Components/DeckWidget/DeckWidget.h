//
// Created by Pierre Roussel on 6/14/23.
//

#ifndef LO21_PROJECT_DECKWIDGET_H
#define LO21_PROJECT_DECKWIDGET_H

#include "../../../Constants/Constants.h"
#include "../../../Controller/DeckController.h"
#include "../../../Controller/GameplayController.h"
#include "../../Style/Style.h"

#include <QMouseEvent>
#include <QPainter>
#include <QWidget>

// For debugging purposes
#include <iostream>

using namespace Controller;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class DeckWidget;
}
QT_END_NAMESPACE

namespace View::Components {
class DeckWidget : public QWidget {
  Q_OBJECT

public:
  explicit DeckWidget(DeckType deckType = DeckType::NORMAL, QWidget *parent = nullptr);
  ~DeckWidget() override;

  void toggle();

public slots:
  void requestInitializePlayersHands(ModeOptions mode = ModeOptions::NORMAL);
  void canPlayerReceiveCard(bool canReceive);

signals:
  void toggled();// by user or program
  void checkPlayerCanReceiveCardSignal(string playerName);
  void normalCardDrawn(shared_ptr<NormalCard> card, string playerName);
  void tacticCardDrawn(shared_ptr<TacticCard> card, string playerName);
  void normalCardDrawnForInitilization(
      std::shared_ptr<std::vector<std::shared_ptr<NormalCard>>> card,
      std::string playerName
      );

protected:
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;

private:
  Ui::DeckWidget *ui;
  bool m_mouseDown_ = false;
  DeckType deckType_ = DeckType::NORMAL;
  unsigned int remainingCards_ = 0;

  shared_ptr<vector<shared_ptr<NormalCard>>> drawNormalCards(unsigned int numberOfCards = 1);
};
}// namespace View::Components

#endif//LO21_PROJECT_DECKWIDGET_H