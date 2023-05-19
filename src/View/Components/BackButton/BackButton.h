//
// Created by Pierre Roussel on 5/12/23.
//

#ifndef LO21_PROJECT_BACKBUTTON_H
#define LO21_PROJECT_BACKBUTTON_H

#include "../../Style/Style.h"

#include <QPushButton>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class BackButton;
}
QT_END_NAMESPACE

class BackButton : public QPushButton {
  Q_OBJECT

public:
  explicit BackButton(QWidget *parent = nullptr);
  ~BackButton() override;

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  Ui::BackButton *ui;
  const QImage backImage_ = QImage("../assets/icons/back.png");
};

#endif//LO21_PROJECT_BACKBUTTON_H
