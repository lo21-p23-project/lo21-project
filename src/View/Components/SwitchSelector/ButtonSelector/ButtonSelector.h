//
// Created by Pierre Roussel on 5/14/23.
//

#ifndef LO21_PROJECT_BUTTONSELECTOR_H
#define LO21_PROJECT_BUTTONSELECTOR_H

#include "../../../Style/Style.h"

#include <QPainter>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class ButtonSelector;
}
QT_END_NAMESPACE

namespace View::Components {

class ButtonSelector : public QPushButton {
  Q_OBJECT

public:
  explicit ButtonSelector(const std::string &title = "Default", int index = 0, bool selected = false, QWidget *parent = nullptr);
  ~ButtonSelector() override;

public slots:
  void setSelected(int index);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  Ui::ButtonSelector *ui;

  QString title_;
  int index_;
  bool selected_ = false;
};
}// namespace View::Components

#endif//LO21_PROJECT_BUTTONSELECTOR_H
