//
// Created by Pierre Roussel on 5/10/23.
//

#ifndef LO21_PROJECT_SWITCHBUTTON_H
#define LO21_PROJECT_SWITCHBUTTON_H

#include "../../Style/Style.h"

#include <QMouseEvent>
#include <QPainter>
#include <QWidget>

// For debugging purposes
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
class SwitchButton;
}
QT_END_NAMESPACE

namespace View::Components {

class SwitchButton : public QWidget {
  Q_OBJECT
  Q_PROPERTY(bool checked READ isChecked WRITE setChecked NOTIFY toggled)

public:
  explicit SwitchButton(QWidget *parent = nullptr);
  ~SwitchButton() override;

  void setChecked(bool checked);
  bool isChecked() const;

  void toggle();

  QSize sizeHint() const override;

signals:
  void checked(bool checked);// by user
  void toggled(bool checked);// by user or program

protected:
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

private:
  Ui::SwitchButton *ui;
  bool m_checked_ = false;
  bool m_mouseDown_ = false;
};
}// namespace View::Components

#endif//LO21_PROJECT_SWITCHBUTTON_H
