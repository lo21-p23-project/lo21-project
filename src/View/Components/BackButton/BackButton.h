//
// Created by Pierre Roussel on 5/12/23.
//

#ifndef LO21_PROJECT_BACKBUTTON_H
#define LO21_PROJECT_BACKBUTTON_H

#include "../../Style/Style.h"

#include <QPainter>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class BackButton;
}
QT_END_NAMESPACE

namespace View::Components {

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
}// namespace View::Components

#endif//LO21_PROJECT_BACKBUTTON_H
