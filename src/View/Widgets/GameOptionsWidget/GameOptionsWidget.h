//
// Created by Pierre Roussel on 5/6/23.
//

#ifndef LO21_PROJECT_GAMEOPTIONSWIDGET_H
#define LO21_PROJECT_GAMEOPTIONSWIDGET_H

#include "../../Components/Button/Button.h"
#include "../../Components/SwitchButton/SwitchButton.h"
#include "../../Components/SwitchSelector/SwitchSelector.h"
#include "../StackedChildWidget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class GameOptionsWidget;
}
QT_END_NAMESPACE

class GameOptionsWidget : public StackedChildWidget {
  Q_OBJECT

public:
  explicit GameOptionsWidget(GameVersion gameVersion, Widgets widget, int index, QWidget *parent = nullptr);

  ~GameOptionsWidget() override;

public slots:
  void setTacticModeSlot();
  void setExpertModeSlot();
  void setAImodeSlot();
  void setNbRoundsSlot(int nbRounds);

private:
  Ui::GameOptionsWidget *ui;

  GameVersion gameVersion_;
  bool tacticMode_ = false;
  bool expertMode_ = false;
  bool aiMode_ = false;
  int nbRounds_ = 1;
};

#endif//LO21_PROJECT_GAMEOPTIONSWIDGET_H
