//
// Created by Pierre Roussel on 6/14/23.
//

#ifndef LO21_PROJECT_DECKWIDGET_H
#define LO21_PROJECT_DECKWIDGET_H

#include "../../../Constants/Constants.h"
#include "../../Style/Style.h"

#include <QMouseEvent>
#include <QPainter>
#include <QWidget>

// For debugging purposes
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class DeckWidget;
}
QT_END_NAMESPACE

namespace View::Components {
class DeckWidget : public QWidget {
  Q_OBJECT

public:
  explicit DeckWidget(const GameVersion gameVersion = GameVersion::VERSION1, QWidget *parent = nullptr);
  ~DeckWidget() override;

  void toggle();

signals:
  void toggled();// by user or program

protected:
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;

private:
  Ui::DeckWidget *ui;
  bool m_mouseDown_ = false;
};
}// namespace View::Components

#endif//LO21_PROJECT_DECKWIDGET_H
