//
// Created by Pierre Roussel on 6/1/23.
//

#ifndef LO21_PROJECT_HANDWIDGET_H
#define LO21_PROJECT_HANDWIDGET_H

#include "../../../Constants/Constants.h"
#include "../../../Controller/GameplayController.h"
#include "../../Constants/CardSlotType.h"
#include "../../Style/Style.h"
#include "../CardManager/CardManager.h"
#include "../CardSlot/CardSlot.h"
#include "../DragableCard/DragableCard.h"

#include <vector>

#include <QGridLayout>
#include <QWidget>

using namespace Controller;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class HandWidget;
}
QT_END_NAMESPACE

namespace View::Components {

class HandWidget : public QWidget {
  Q_OBJECT

public:
  explicit HandWidget(string playerUsernameHand, CardManager *cardManager, QWidget *parent = nullptr);
  ~HandWidget() override;

  void setPlayerUsernameHand(string playerUsernameHand) {
    playerUsernameHand_ = playerUsernameHand;
  };

public slots:
  void checkPlayerCanReceiveCard(string playerName);
  void receiveNormalCardDrawn(shared_ptr<NormalCard> card, string playerName);
  void receiveTacticCardDrawn(shared_ptr<TacticCard> card, string playerName);
  void receiveInitializePlayersHands(shared_ptr<vector<shared_ptr<NormalCard>>> cards, string playerName);

signals:
  void playerCanReceiveCardSignal(bool canReceive);

private:
  Ui::HandWidget *ui;

  string playerUsernameHand_;
  CardManager *cardManager_;
  std::vector<CardSlot *> slots_;
};
}// namespace View::Components

#endif//LO21_PROJECT_HANDWIDGET_H