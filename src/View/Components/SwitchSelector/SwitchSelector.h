//
// Created by Pierre Roussel on 5/13/23.
//

#ifndef LO21_PROJECT_SWITCHSELECTOR_H
#define LO21_PROJECT_SWITCHSELECTOR_H

#include "../../Style/Style.h"
#include "./ButtonSelector/ButtonSelector.h"

#include <vector>

#include <QHBoxLayout>
#include <QPainter>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class SwitchSelector;
}
QT_END_NAMESPACE

namespace View::Components {

class SwitchSelector : public QWidget {
  Q_OBJECT

public:
  explicit SwitchSelector(const std::vector<std::string> &titles = {}, int initialIndex = 0, QWidget *parent = nullptr);
  ~SwitchSelector() override;

public slots:
  void selectedIndexChanged(int index);

signals:
  void selectedIndexChangedSignal(int index);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  Ui::SwitchSelector *ui;

  int selectedIndex_ = 0;
  std::vector<ButtonSelector *> buttons_;
};
}// namespace View::Components

#endif//LO21_PROJECT_SWITCHSELECTOR_H
