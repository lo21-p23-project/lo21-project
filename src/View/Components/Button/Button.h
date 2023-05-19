//
// Created by Pierre Roussel on 5/11/23.
//

#ifndef LO21_PROJECT_BUTTON_H
#define LO21_PROJECT_BUTTON_H

#include "../../Style/Style.h"

#include <QPushButton>
#include <QLabel>
#include <QPainter>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class Button;
}
QT_END_NAMESPACE

class Button : public QPushButton {
  Q_OBJECT

public:
  explicit Button(const std::string& title = "Button", bool reversed = false, QWidget *parent = nullptr);
  ~Button() override;

  void setReversed(bool reversed);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  Ui::Button *ui;
  bool m_mouseDown_ = false;
  QString title_;
  bool reversed_ = false;
};

#endif//LO21_PROJECT_BUTTON_H
